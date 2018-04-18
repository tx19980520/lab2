#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Input.H>
#include <FL/fl_draw.H>
#include "calculator.h"
#include <FL/Fl_Button.H>
using namespace std;
#ifndef _FUNC_WINDOW_H
#define _FUNC_WINDOW_H
class FuncDraw:public Fl_Widget{
    public:
        FuncDraw(int x,int y,int w, int h, const char*title,Calc *core):Fl_Widget(x,y,w,h,title)
        {
            this->core = core;
            init = false;
        };
        void create(const char*);
        void draw();//for draw the function
    private:
        Calc *core;
        bool init;
            
};
class FuncWindow:public Fl_Window{
    public:
        FuncWindow(int x,int y,const char*title, Calc * core):Fl_Window(x,y,title)
        {
            funcDraw = new FuncDraw(20,100,x-20,y-100,"func",core);
            funcDraw->show();
            funcInput = new Fl_Input(x/2-100,20,200,60,"f(x)=");
            funcButton = new Fl_Button(x/2+120,20,80,60,"draw function");
            funcButton->callback(drawFunc,this);
        };
    private:
        FuncDraw *funcDraw;
        Calc *core;//我所有的有关计算的东西都是用的一棵树
        Fl_Input *funcInput;
        Fl_Button *funcButton;
        static void drawFunc(Fl_Widget*,void*);
        
};
#endif