#include "FL/fl_draw.H"
#include "treemodel.h"
using namespace std;
#ifndef _DRAW_WINDOW_H
#define _DRAW_WINDOW_H
struct drawnode{
  int x;
  int y;
  bool red;
  string word;
};
class DrawWindow:public Fl_Window{
  public:
    DrawWindow(int w,int h,const char* title,Calc* Core):Fl_Window(w,h,title)
    {
        this->core = Core;
        /*int len = data.size();
        fl_line(300,300,400,400);
        for(int i=0;i<len;++i)
        {
          Fl_Box *tmp;
          tmp = new Fl_Box(data[i].x,data[i].y,boxlen,boxhei,data[i].word.c_str());
          if(data[i].red)
            tmp->color(FL_RED);
          tmp->box(FL_UP_BOX);
          tmp->labelfont(FL_BOLD+FL_ITALIC);
          boxes.push_back(tmp);
        }
        */
    };
    ~DrawWindow(){};
    void draw();
  private:
    int boxlen = 80;
    int boxhei = 60;
    Calc *core;
    vector<drawnode> data;
    void travelseral(node *root,int x,int y,int xlen);//遍历结构树并且画图
};
#endif