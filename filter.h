#include<regex>
#include<iostream>
#include <utility>
#include<string>
using namespace std;




#ifndef _FILTER_H
#define _FILTER_H
typedef pair<bool, string> Final;
//����ʼ�Ŀո�����ķֺ�
string cleanBlankFilter(string input);
//ȷ���Ƿ��й涨��Χ֮����ַ�
bool extraCharFilter(string input);
//���ڲ�������ѧ�߼��Ĵ����ָ��
Final formatCharFilter(string input);

//�õ�����
string UserInput();

string InputAndFilter();//���ϲ��ֵ�������
#endif