#include "main_window.h"
#include "calc_button.h"
#include "show_result.h"
#include "func_window.h"
#include "calculator.h"
#include "treemodel.h"
#include "filter.h"
#include "calc_output.h"
#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>
#include <sstream> 
#include <cmath>
using namespace std;
void MainWindow::getToken(Fl_Widget*v, void *o)//get token
{
    ((MainWindow*)o)->Output->getToken(((Calc_Button*)v)->getTitle());

}
void MainWindow::actionAC(Fl_Widget*v, void *o)
{
    /*to do to flush*/
    ((MainWindow*)o)->Output->action_ac();
    ((MainWindow*)o)->Result->setResult("");
}

void MainWindow::actionDEL(Fl_Widget*v, void *o)
{
    /*to do to flush*/
    ((MainWindow*)o)->Output->action_del();
}

void MainWindow::show_function()
{
    funcImage = new FuncWindow(800,600,"function",this->CalcCore);
    funcImage->show();
}

void MainWindow::getFunc(Fl_Widget*v, void *o)
{
    ((MainWindow*)o)->show_function();
}

void MainWindow::actionEqual(Fl_Widget*v, void *o)
{
    /*get the result */
   string input =  ((MainWindow*)o)->Output->getNow();
   ((MainWindow*)o)->Output->push();
   input = cleanBlankFilter(input);
	if(input=="")
    {
        ((MainWindow*)o)->Result->setResult("error");
        return;
    }
	Final result = formatCharFilter(input);
	if (extraCharFilter(input) || !result.first)//表示是异常输入
    {
        ((MainWindow*)o)->Result->setResult("error");
        return;
    }
    ((MainWindow*)o)->CalcCore = new Calc(result.second);
    double r = ((MainWindow*)o)->CalcCore->result();
	if (r > 999999)
	{
	    ((MainWindow*)o)->Result->setResult("error");
    }
    else {
        ((MainWindow*)o)->Result->setResult(r);
	}

}
void MainWindow::actionUp(Fl_Widget*v, void *o)
{
    ((MainWindow*)o)->Output->getBack();
}

void MainWindow::actionDown(Fl_Widget*v, void *o)
{
    ((MainWindow*)o)->Output->getFront();
}

MainWindow::MainWindow(int w, int h,const char* title):Fl_Window(w,h,title)
{
    begin();
    int length = w;//600
    int height = h;//800
    int buttonLen = 80;
    int buttonHei = 60;
    row = 2;
    line = 3;
    float ratio = 0.5;
    CalcCore = new Calc("0");
    Output = new Calc_Output(length/2-100,0,200,60,"Input");
    Result = new showResult(length/2-100,80,200,60,"Result");
    UpButton = new Calc_Button(length/2-50,150,buttonLen,buttonHei,"@8>");
    UpButton->callback(actionUp,this);
    DrawButton = new Calc_Button(length/2+200,150,buttonLen,buttonHei,"Draw");
    DrawButton->callback(getNew,this);
    FuncButton = new Calc_Button(length/2-200-buttonLen,150,buttonLen,buttonHei,"Func");
    FuncButton->callback(getFunc,this);
    DownButton = new Calc_Button(length/2-50,150+buttonHei+20,buttonLen,buttonHei,"@2>");
    DownButton->callback(actionDown,this);
    signs.push_back("7");
    signs.push_back("8");
    signs.push_back("9");
    signs.push_back("/");
    signs.push_back("DEL");//4
    signs.push_back("AC");//5
    //for the first line

    signs.push_back("4");
    signs.push_back("5");
    signs.push_back("6");
    signs.push_back("*");
    signs.push_back("(");
    signs.push_back(")");
    //for the second line

    signs.push_back("1");
    signs.push_back("2");
    signs.push_back("3");
    signs.push_back("-");
    signs.push_back("!");
    signs.push_back("ANS");//17
    //for the third line

    signs.push_back("0");
    signs.push_back(".");
    signs.push_back("%");
    signs.push_back("+");
    signs.push_back("=");//22
    //for the forth line

        for( row= 1;row <= 4;++row)//about 9
        {
            for(line = 1;line <= 6; ++line)
            {
                switch((row-1)*6+line-1)
                {
                    case 4:{//DEL
                        Calc_Button *tmp;
                        tmp = new Calc_Button(length/2-(4-line)*(buttonLen+10),height*ratio+(row-1)*(buttonHei+10),buttonLen,buttonHei,signs[(row-1)*6+line-1]);
                        tmp->callback(actionDEL,this);
                        Numbers.push_back(tmp);
                        break;
                    }
                    case 5:{//AC
                        Calc_Button *tmp;
                        tmp = new Calc_Button(length/2-(4-line)*(buttonLen+10),height*ratio+(row-1)*(buttonHei+10),buttonLen,buttonHei,signs[(row-1)*6+line-1]);
                        tmp->callback(actionAC,this);
                        Numbers.push_back(tmp);
                        break;
                    }
                    case 22:{//= double the space
                        Calc_Button *tmp;
                        tmp = new Calc_Button(length/2-(4-line)*(buttonLen+10),height*ratio+(row-1)*(buttonHei+10),buttonLen*2+10,buttonHei,signs[22]);
                        tmp->callback(actionEqual,this);
                        Numbers.push_back(tmp);
                        break;
                    }
                    case 23:{// the last lack
                        break;
                    }
                    default:{ // normal button
                        Calc_Button *tmp;
                        tmp = new Calc_Button(length/2-(4-line)*(buttonLen+10),height*ratio+(row-1)*(buttonHei+10),buttonLen,buttonHei,signs[(row-1)*6+line-1]);
                        tmp->callback(getToken,this);
                        Numbers.push_back(tmp);
                        break;
                    }
                }
            }
        }
    end();
}
void MainWindow::getNew(Fl_Widget *v, void* o)
{
    ((MainWindow*)o)->getNew_i();
}
void MainWindow::window_cb(Fl_Widget *window, void *o)
{
    ((MainWindow*)o)->window_i();
}
void MainWindow::window_i(){
    int result = fl_choice("Do you want to quit?", 
                           "Yeah",  // 0
                           "No",        // 1
                           "Cancel"       // 2
                           );
    if (result == 0) {  
        this->hide();
    }
}
void MainWindow::getNew_i()
{
    next = new DrawWindow(800,600,"Test",this->CalcCore);
    next->callback(window_cb,next);
    next->show();
}