#include "calc_output.h"
#include <vector>
#include <string>
#include "string.h"
#include <iostream>
using namespace std;
void Calc_Output::getBack()
{
    if(pos == -1)
        return;
    pos --;
    if(!val)
    delete val;
    val = new char [sizeof(buffer[pos])];
    cout << "back" <<endl;
    cout << buffer[pos]<<endl;
    strcpy(val,buffer[pos]);
    this->value(val);
}

void Calc_Output::getFront()
{
    if(pos == (int)buffer.size()-1)
     return;
    pos ++;
    if(!val)
    delete val;if(!val)
    cout<< "front"<<endl;
    cout << buffer[pos] <<endl;
    val = new char [sizeof(buffer[pos])];
    strcpy(val,buffer[pos]);
    this->value(val);
}


string Calc_Output::getNow()
{
    buffer.push_back(this->val);
    pos = buffer.size()-1;
    string str(buffer[pos]);
    return str;
}

void Calc_Output::action_ac()
{
    this->value("");
    if(!val)
    delete val;
    buffer.clear();
}

void Calc_Output::action_del()
{
    this->cut(1);
    if(!val)
    delete val;
    val = new char [strlen(this->value())];
    strcpy(val,this->value());
}

void Calc_Output::push()
{
    this->newone = true;
}

void Calc_Output::getToken(const char* add)
{
    if(!val)
    delete val;
    int charpos = position();
    if(charpos == 0)//这个地方先是一个简单的c写法，下面的操作比较复杂用了一个c++的转换，再转回c
    {
        if(newone)
        {
            newone = false;//表示这是在一个新的状态下进行的计算式编写。
            this->value("");
        }
        val = new char [strlen(this->value())+strlen(add)];
        strcpy(val,this->value());
        strcat(this->val,const_cast<char*>(add));
        this->value(this->val);
    }
    else{
        if(newone)
        {
            newone = false;//表示这种情况下表示要在该计算式下进行修改，则只需要取消状态即可
        }
        val = new char [strlen(this->value())+strlen(add)];
        string sadd = add;
        string devide = this->value();
        devide.insert(charpos,sadd);
        cout << devide <<endl;
        strcpy(val,devide.c_str());
        this->value(val);
    }
}