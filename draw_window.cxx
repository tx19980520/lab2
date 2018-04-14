#include "draw_window.h"
#include <FL/fl_draw.H>
using namespace std;

void DrawWindow::drawTree(Fl_Widget*v,void*o)
{
    //((DrawWindow*)o)->draw();
}
void DrawWindow::draw()
{
    fl_begin_line();
        this->travelseral(core->getRoot(),this->x,this->y);
    fl_end_line();
}
void DrawWindow::travelseral(node *root,int x,int y)//fathers pos
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
        default:{
            break;
        }
   }
    node.x = x-30;
    node.y = y;
    node.red = 0;
    data.push_back(node);
    int i = data.size()-1;
    if(root->left != NULL)
        fl_line(data[i].x+boxlen/2,data[i].y+boxhei,data[i].x+boxlen/2-45,data[i].y+80);
    if(root->right != NULL)
        fl_line(data[i].x+boxlen/2,data[i].y+boxhei,data[i].x+boxlen/2+45,data[i].y+80);
        Fl_Color f;
        f = FL_BLACK;
        if(data[i].red)
            f = FL_RED;
        fl_rect(data[i].x,data[i].y,boxlen,boxhei,f);
        fl_draw(data[i].word.c_str(),data[i].x+5,data[i].y+boxhei/2);
    this->travelseral(root->left,x-45,y+80);
    this->travelseral(root->right,x+45,y+80);
    
}