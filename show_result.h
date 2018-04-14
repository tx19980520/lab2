#include <FL/Fl_Output.H>
#include <iostream>
using namespace std;
#ifndef _SHOW_RESULT_H
#define _SHOW_RESULT_H
class showResult:public Fl_Output
{
    private:
     char* val;
    public:
        showResult(int x,int y, int w,int h,const char*l):Fl_Output(x,y,w,h,l){
            val = nullptr;
        }
        void setResult(const char*);
        void setResult(double);
};
#endif