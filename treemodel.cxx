#include "treemodel.h"
#include <FL/Fl.H>
#include <FL/fl_draw.H>
#include <FL/Fl_Box.H>
using namespace std;
void TreeModel::travelseral(node *root,int x,int y)//fathers pos
{
    if(root == NULL)
        return;
    Fl_Box *tmp;
    tmp = new Fl_Box(x-40,y-80,boxlen,boxhei,"fuck");
    if(!root->isRight)
        tmp->color(FL_RED);
    tmp->box(FL_UP_BOX);
    tmp->labelfont(FL_BOLD+FL_ITALIC);
    tmp->labelsize(36);
    tmp->labeltype(FL_SHADOW_LABEL);
    tmp->show();
    boxes.push_back(tmp);
    this->travelseral(root->left,x-40,y-80);
    this->travelseral(root->right,x+40+boxlen,y-80);
}
void TreeModel::draw()
{
    fl_overlay_clear();
    fl_color(FL_BLACK);
    int py = 550/2+20;
    int px = 20;
    this->travelseral(Core->getRoot(),400-40,20);
    this->hide();
    this->show();
    fl_begin_line();
        fl_line(100,200,300,400);
    fl_end_line();
    redraw();
}