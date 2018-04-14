#include <FL/fl_draw.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include "calculator.h"
#ifndef _TREEMODEL_H
#define _TREEMODEL_H
using namespace std;
class TreeModel:public Fl_Widget{
    private:
        vector<Fl_Box*> boxes;
        Calc* Core;
        int boxlen = 80;
        int boxhei = 60;
    public:
        void travelseral(node *root,int x,int y);
        void draw();
        TreeModel(int x, int y,int w,int h,Calc* Core):Fl_Widget(x,y,w,h,"Tree")
        {
            this->Core = Core;
        };
};
#endif