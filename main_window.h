#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>
#include <sstream> 
#include <cmath>
#include "calc_button.h"
#include "calculator.h"
#include "draw_window.h"
#include "func_window.h"
#include "filter.h"
#include "treemodel.h"
#include "show_result.h"
#include "calc_output.h"
#include "calc_button.h"
#include <vector>
#ifndef _MAIN_WINDOW_H
#define _MAIN_WINDOW_H


using namespace std;
class MainWindow:public Fl_Window{
  public:
    MainWindow(int w,int h,const char* title);
    ~MainWindow(){};
    vector<Calc_Button*> Numbers;
  private:
    int row ;
    int line;
    Calc *CalcCore;
    DrawWindow *next;
    FuncWindow *funcImage; 
    Calc_Output *Output;
    showResult *Result;
    Calc_Button *DrawButton;
    Calc_Button *FuncButton;
    Calc_Button *UpButton;
    Calc_Button *DownButton;
    vector<const char*> signs;
    static void window_cb (Fl_Widget*, void *);//ask for the close
    static void getToken(Fl_Widget*, void *);//get char from button
    static void actionAC(Fl_Widget*, void *);// calc AC function flush all.
    static void actionESC(Fl_Widget*, void *);// calc ESC function  close the window
    static void actionDEL(Fl_Widget*, void *);// calc DEL function delete a char
    static void actionEqual(Fl_Widget*, void *);// calc = function get the result value
    static void actionUp(Fl_Widget*, void *);
    static void getFunc(Fl_Widget*, void *);
    static void actionDown(Fl_Widget*, void *);
    void window_i();
    void show_function();
    static void getNew(Fl_Widget*,void*);//get specific data for drawing
    inline void getNew_i();
    void drawCoch(); 
};
#endif