#include<regex>
#include<iostream>
#include <utility>
#include<string>
#include "filter.h"
using namespace std;




string cleanBlankFilter(string input)//����ʼ�Ŀո�����ķֺ�
{
	smatch match;
	regex clean("(.*)");
	regex_match(input, match, clean, regex_constants::match_default);//��һ����Ҫ���ڽ�����ӵ�ANS�����⣬�Ȱ�ANS�滻��������һ���ļ��
	return match[1];
}
//ȷ���Ƿ��й涨��Χ֮����ַ�
bool extraCharFilter(string input)
{
	smatch match;
	regex errorRegex1("ANS");
	string replaceANS = regex_replace(input, errorRegex1, "0");//��һ����Ҫ���ڽ�����ӵ�ANS�����⣬�Ȱ�ANS�滻��������һ���ļ��
	regex errorRegex2("([^0-9\\+\\*-/%\\(\\)/!x])");   // ���ڷǹ涨�ַ����ų������������Ѿ�������ANS��Ӱ��
	return regex_search(replaceANS, match, errorRegex2);
}
//���ڲ�������ѧ�߼��Ĵ����ָ��
Final formatCharFilter(string input)
{
	Final result;
	smatch match;
	regex mutipleAdd("\\+{2,}");
	regex doubleMinus("--");
	regex mixAddMinus("(\\+-)|(-\\+)");
	bool mid = 1;
	while (regex_search(input, match, mutipleAdd) || regex_search(input, match, doubleMinus) || regex_search(input, match, mixAddMinus))
	{
		if (regex_search(input, match, mutipleAdd))
			input = regex_replace(input, mutipleAdd, "+");
		if (regex_search(input, match, doubleMinus))
			input = regex_replace(input, doubleMinus, "+");
		if (regex_search(input, match, mixAddMinus))
			input = regex_replace(input, mixAddMinus, "-");
	}//����whileѭ��ʵ���˽�input�е����������++--���������Ҵ����������У��Լ���������в�����-+ +-��
	 //�߼��Ͻ���������������ȷ������Ѿ��������ˣ�����ֻʣ�´���������������ϵ�����������������Ĵ������������
	regex errorRegex("(\\+[\\*%!/])|(-[\\*%!/])|(\\*[\\*/!%])|(/[\\*/!%])|(%[\\*%!])");//ȥ������+/ +* +! -* \! -/ -*
	if (regex_search(input, match, errorRegex))
	{
		mid = 0;
		result.first = mid;
		result.second = "";
		return result;
	}
	//�����forѭ����������ƥ�������
	int len = input.length();
	int count = 0;
	for (int i = 0; i<len; ++i)
	{
		if (input[i] == '(')
			count++;
		if (input[i] == ')')
			count--;//���������ǲ����ܳ��ָ�����
		if (count <0)
		{
			mid = 0;
			break;
		}
	}
	if (count != 0)
		mid = 0;
	result.first = mid;
	result.second = input;
	return result;
}


string UserInput()
{
	cout << "> " << flush;
	string input;
	getline(cin, input);
	return input;
}

string InputAndFilter()//���ϲ��ֵ�������
{
	string input = UserInput();
	input = cleanBlankFilter(input);
	if(input=="")
		return "error";
	Final result = formatCharFilter(input);
	if (extraCharFilter(input) || !result.first)//��ʾ���쳣����
		return "error";
	else return result.second;
}