#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Int_Input.H>
#include <FL/fl_draw.H>
#include <FL/fl_ask.H>
#include <iostream>
#include <string>
#include <sstream> 
#include <cmath>
#include "main_window.h"
#include "draw_window.h"
#include "filter.h"
#include "calculator.h"
using namespace std;
#define PI 3.14159265
const int LEN = 486;

int main() {
MainWindow win(800,600,"Calculator");
win.show();
return Fl::run();
}