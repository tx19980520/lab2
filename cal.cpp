#include<string>
#include<cmath>
#include "calculator.h"
#include "filter.h"

int main()
{
	while (true)
	{
		string input = InputAndFilter();//����ؼ������filter.h
		if (input == "error")
		{
			cout << "error" << endl;
			continue;
		}
		else {
			Calc *cal = new  Calc(input);
			double result = cal->result();
			if (result > 999999)
			{
				cout << "error" << endl;
				calcError = false;//��֪�����̲�һ�ο�һ�γ�����һ�β��꣬ÿ���������ֵ��Ū��false
				continue;
			}
			else {
				cout << "= " << result << endl;
			}
		}
	}
}