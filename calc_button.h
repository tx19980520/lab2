#include<FL/Fl_Button.H>
#include<iostream>
#include<string>
#include "string.h"
using namespace std;
#ifndef _CALC_BUTTON_H
#define _CALC_BUTTON_H
class Calc_Button: public Fl_Button{
    public:
        Calc_Button(int x,int y, int l,int h,const char*waste):Fl_Button(x,y,l,h,waste){
            title = new char [sizeof(waste)];
            strcpy(this->title,waste);
            this->label(this->title);
        };
        const char* getTitle();//return the title;
        char *title;
};
#endif