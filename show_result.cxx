#include "show_result.h"
#include <sstream>
#include "string.h"
#include <string>
using namespace std;
void showResult::setResult(const char* result)
{
    if(!val)
    delete val;
    val = new char [sizeof(result)];
    strcpy(val,result);
    this->value(val);
}
void showResult::setResult(double result)
{
    if(!val)
    delete val;
    val = new char [to_string(result).length()];
    strcpy(val,to_string(result).c_str());
    cout << val <<endl;
    this->value(val);
}