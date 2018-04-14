################ template makefile ##############
# We don't know what compiler to use to build fltk on this machine - but fltk-config does...
CC  = $(shell fltk-config --cc)
CXX = $(shell fltk-config --cxx)

# Set the flags for compiler: fltk-config knows the basic settings, then we can add our own...
CFLAGS   = $(shell fltk-config --cflags) -Wall -O3 -I/usr/local/include 
CXXFLAGS = $(shell fltk-config --cxxflags) -Wall -O3 -std=c++11

# We don't know what libraries to link with: fltk-config does...
LINKFLTK = $(shell fltk-config --ldstaticflags)

# Define what your target application is called
all: Calculator

# Define how to build the various object files...
calculator.o : calculator.cxx calculator.h
	g++ -c -std=c++11 calculator.cxx

filter.o: filter.cxx filter.h
	g++ -c -std=c++11 filter.cxx

treemodel.o: treemodel.cxx treemodel.h calculator.h
	g++ -c -std=c++11 treemodel.cxx
# draw_window是必须得在main_window中组合
calc_button.o : calc_button.cxx calc_button.h
	$(CXX) -c $< $(CXXFLAGS)

calc_output.o : calc_output.cxx calc_output.h
	$(CXX) -c $< $(CXXFLAGS)

show_result.o : show_result.cxx show_result.h
	$(CXX) -c $< $(CXXFLAGS)

draw_window.o : draw_window.cxx draw_window.h treemodel.h calculator.h
	$(CXX) -c $< $(CXXFLAGS)

func_window.o : func_window.cxx func_window.h calculator.h
	$(CXX) -c $< $(CXXFLAGS)

main_window.o: main_window.cxx main_window.h draw_window.h func_window.h calc_button.h calculator.h show_result.h calc_output.h treemodel.h
	$(CXX) -c $< $(CXXFLAGS)

main.o: main.cxx main_window.h draw_window.h filter.h calculator.h 
	$(CXX) -c $< $(CXXFLAGS)

Calculator: main.o calculator.o filter.o draw_window.o main_window.o calc_button.o show_result.o calc_output.o treemodel.o func_window.o
	$(CXX) -o $@ main.o calculator.o filter.o draw_window.o main_window.o calc_button.o show_result.o calc_output.o treemodel.o func_window.o $(LINKFLTK)
clean:
	rm -f $(binaries) *.o Calculator
############### end #################
