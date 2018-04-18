#include <FL/fl_draw.H>
#include "func_window.h"
#include "calculator.h"
#include "filter.h"
using namespace std;
void FuncDraw::draw()
{
    fl_color(FL_BLACK);    
    if(!init)
    {
        fl_begin_line();//在没有初始化的时候先画坐标轴，我们的原点在400 350
        fl_line(400,100,400,600);
        fl_line(150,350,650,350);
        //我们的坐标比例氏横轴为50 :1
        fl_draw("-5",405,600);
        fl_draw("-4",405,550);
        fl_draw("-3",405,500);
        fl_draw("-2",405,450);
        fl_draw("-1",405,400);

        fl_draw("1",405,300);
        fl_draw("2",405,250);
        fl_draw("3",405,200);
        fl_draw("4",405,150);
        fl_draw("5",405,100);

        fl_draw("-5",150,345);
        fl_draw("-4",200,345);
        fl_draw("-3",250,345);
        fl_draw("-2",300,345);
        fl_draw("-1",350,345);

        fl_draw("1",450,345);
        fl_draw("2",500,345);
        fl_draw("3",550,345);
        fl_draw("4",600,345);
        fl_draw("5",650,345);

        fl_draw("0",405,345);
        for (int i=150;i<=650;i+=50)
            fl_line(i,350,i,347);
        for (int i=100; i<=600; i+=50)
            fl_line(400,i,403,i);
        fl_end_line();
        return ;
    }
    int lastx;
    int lasty;
    fl_begin_line();
    for(int i=150;i<=650;++i)
    {
        double x = (i-400.0)/50;
        point tmp = this->core->result(x);
        if(tmp.second == MAX)
        {
            cout << "MAX" <<endl;
            continue;
        }
        int y = 350-tmp.second * 50;
        if(i ==150)
        {
            lastx = i;
            lasty = y;
            continue;
        }
        if(y>100)
        {
            fl_line(i,y,lastx,lasty);
        }
        lastx = i;
        lasty = y;
    }
    fl_end_line();
    init = false;
    this->hide();
    this->show();
}
void FuncDraw::create(const char* a)
{
    string input = a;
    input = cleanBlankFilter(input);
	if(input=="")
    {
        return;
    }
	Final result = formatCharFilter(input);
	if (extraCharFilter(input) || !result.first)//表示是异常输入
    {
        return;
    }
    this->core->create(result.second);
    init = true;
    this->redraw();
}
void FuncWindow::drawFunc(Fl_Widget*v,void*o)
{
    ((FuncWindow*)o)->funcDraw->create(((FuncWindow*)o)->funcInput->value());// O(length/2,300)
    
}