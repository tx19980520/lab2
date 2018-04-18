#include "draw_window.h"
#include <FL/fl_draw.H>
#include <cmath>
using namespace std;

void DrawWindow::draw()
{
    int level = core->getRoot()->level-1;
    if(level == 0)
        return;
    int total = pow(2,level); 
    this->resize(0,0,total*(boxlen+15)+100,level*(boxhei+30)+100);
    fl_begin_line();
        this->travelseral(core->getRoot(),total*(boxlen+15)/2+50,30,total*(boxlen+15)/4+25);
    fl_end_line();
}
void DrawWindow::travelseral(node *root,int x,int y,int xlen)//fathers pos
{
    if(root == NULL)
        return;
    drawnode node;
   switch(root->character)
   {
       case NUM:{
        string tmp;
        if(root->buff)
            tmp = "-";
        tmp+= to_string(root->value);
        if(root->isFac)
            tmp +="!";
        node.word = tmp.c_str();
           break;
           }
       case ADD:{
           node.word = "+";
           break;
           }
       case SUB:{
           node.word = "-";
           break;
           }
       case MULTI:{
           node.word = "*";
           break;
           }
       case DIV:{
           node.word = "/";
           break;
           }
       case MOD:{
           node.word = "%";
           break;
           }
       case ANS:{
           node.word = "ANS";
           break;
           }
        case X:
        {
            node.word = "x";
        }
        default:{
            break;
        }
   }
    node.x = x-boxlen/2;
    node.y = y;
    node.red = root->isRight;
    data.push_back(node);
    int i = data.size()-1;
    if(root->left != NULL)
    {
        fl_color(FL_BLACK);
        fl_line(data[i].x+boxlen/2,data[i].y+boxhei,x-xlen,data[i].y+boxhei+30);
    }
    if(root->right != NULL)
    {
        fl_color(FL_BLACK);
        fl_line(data[i].x+boxlen/2,data[i].y+boxhei,x+xlen,data[i].y+boxhei+30);
    }
        
        Fl_Color f;
        f = FL_BLACK;
        if(!data[i].red)
            f = FL_RED;
        fl_rect(data[i].x,data[i].y,boxlen,boxhei,f);
        fl_draw(data[i].word.c_str(),data[i].x+5,data[i].y+boxhei/2);
    this->travelseral(root->left,x-xlen,y+boxhei+30,xlen/2);
    this->travelseral(root->right,x+xlen,y+boxhei+30,xlen/2);
    
}