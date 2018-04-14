#include <FL/Fl_Output.H>
#include <vector>
#include <string>
using namespace std;
#ifndef _CALC_OUTPUT_H
#define _CALC_OUTPUT_H
class Calc_Output:public Fl_Output{
    private:
        vector <char*> buffer;
        int pos;
        char* val;
        double ANS;
        bool newone;
    public:
        Calc_Output(int x, int y, int w, int h, const char* title):Fl_Output(x,y,w,h,title){
            pos = -1;
            val= nullptr;
            cursor_color(FL_BLUE);
            newone = false;
        }
        /*change to string in order to be friendly for the back-end*/
        string getNow();
        void getToken(const char*);
        void getBack();
        void getFront();
        void action_del();
        void action_ac();
        void push();
        
};
#endif