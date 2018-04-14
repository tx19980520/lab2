#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Color_Chooser.H>
#include <iostream>
using namespace std;
#ifndef _DRAW_H
#define _DRAW_H
class Drawing:public Fl_Widget{
    private:
        Fl_Color drawColor;
        int N;
    public:
        Drawing(int x,int y,int w,int h,const char *l=0):Fl_Widget(x,y,w,h,l){};
        void setN(int n);
        void setColor(float r,float g,float b);
        void koch(int now ,int deep,int len,int &px,int &py,int direction);
        void draw();
};
#endif