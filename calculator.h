#pragma once
#include<regex>
#include<iostream>
#include <utility>
#include<cmath>
#include<string>
#include<sstream>
using namespace std;











#ifndef _CALCULATOR_H
#define _CALCULATOR_H

enum Type { NUM, ADD, SUB, MULTI, DIV, OPAREN, CPAREN, EOL, MOD, ANS, FAC, NEGA, POS, X };//for switch
typedef pair<Type, string> Token;//我们在这个地方需要我们在token保存一个type，type是一个string,另外的一个部分为具体的数据，主要是为了数字准备的，在不是数据是字符串的时候我们选择为“”
								 //到这一步已经是到了只有计算错误的时候了，就是得有数字参与才会有错误的时候
typedef pair<double,double> point;
extern double ans;//为日后实现ANS功能来做准备
extern const double spe;
extern const double MAX;//在计算过程中出错一律返回MAX，之后我们会check一下，看输出什么
extern bool calcError;
double fac(double x);
struct node {
		Type character;
		node *left;
		node *right;
		double value;
		bool buff;//确保是有一个符号
		bool isRight;
		int isFac;//确保是否是有一个阶乘的buff
		string ch;
		node(Type t, double d = 0.0, string h="!",node * lc = NULL, node * rc = NULL, bool b = false, int fac = 0) {
			character = t;
			string ch = h;
			value = d;
			left = lc;
			right = rc;
			buff = b;
			isFac = fac;
			isRight = true;
		}
	};

class Calc {
	double x;
	node *root;
	node *create(string &input, int& position);
	Token getToken(string &s, int& position);
	double result(node *t);//计算结果
	point result(node *t,double x);
	double getValue(string s);//对于某个节点的值的计算
public:
	Calc(string input) { int position = 0; root = create(input, position); }
	void deleteNode(node *n);
	~Calc()
	{
		deleteNode(root);
	};
	void create(string input)
	{
		node * tmp = root;
		if (tmp != NULL)
			deleteNode(tmp);
		cout << "delete clear" << endl;
		this->root = NULL;
		int position = 0;
		this->root = create(input, position);
		//cout << root->character<<" "<<root->left->character << " " <<root->right->character <<endl;
	}
	node* getRoot();//返回根节点供前端遍历生成语法树
	double result() {//对于private result的封装，返回答案
		if (root == NULL)
		{
			return 0;
		}
		ans = result(root);
		return ans;
	}
	point result(double x)
	{
		return result(root,x);
	}
};
#endif