#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Color_Chooser.H>
#include <iostream>
#include <string>
#include <sstream> 
#include <cmath>
#include "draw.h"
using namespace std;
#define PI 3.14159265
const int LEN = 486;
void Drawing::setN(int n)
{
    N = n;
}
/*int Drawing::handle(int event)
{
    window()->make_current();
    switch(event)
    {
        case FL_DRAG:
        {
            fl_overlay_rect(20,20,550,550);
            return 5;
        }
        case FL_RELEASE:
        {
            fl_overlay_clear();
            return 2;
        }
        default:
        {
            return Fl_Widget::handle(event);
        }

    }
}
*/
void Drawing::setColor(float r, float g,float b)
{
    fl_color(r*256,g*256,b*256);
    drawColor = fl_color();
}
/*
   deep     length
     4        
*/
void Drawing::koch(int now ,int deep,int len,int &px,int &py,int direction) 
{
    if(now < deep)//还得向下递归
    {
        koch(now+1,deep,len/3,px, py,direction);
        koch(now+1,deep,len/3,px, py,direction-60);
        koch(now+1,deep,len/3,px, py,direction+60);
        koch(now+1,deep,len/3,px, py,direction);
    }
    else{
        int dx = len*cos(direction*PI/180.0);
        int dy = len*sin(direction*PI/180.0);
        fl_line(px,py,px+dx,py+dy);
        px += dx;
        py += dy;
        
    }   
}
void Drawing::draw()
{
    fl_overlay_rect(20,20,550,550);
    fl_overlay_clear();
    fl_rectf(20,20,550,550,FL_WHITE);
    fl_color(drawColor);
    int py = 550/2+20;
    int px = 20;
    fl_begin_line();
        koch(0,N,LEN,px,py,0);
    fl_end_line();
    redraw();
}
