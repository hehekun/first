#include <iostream>
#include <fstream>//文件读取存储相关头文件
#include<stack> //栈库函数头文件
#include<string>//字符串头文件
#include <sstream>//字符串流头文件
using namespace std;
string ZM= "C://Users/lenovo/Desktop/";
//所有.txt文件均放在桌面
void mov(int num,string p)//存储（赋值）
{
	ofstream in;
	string place = ZM;
	place +=p; 
	place += ".txt";
	in.open(place, ios::trunc);//ios::trunc表示在打开文件前将文件清空,由于是写入,文件不存在则创建
	in << num;
	in.close();//关闭文件
}
int read(string p)//读取
{
	int num = -1;
	ifstream out;
	string place = ZM;
	place += p;
	place += ".txt";
	out.open(place);//打开对应地址的.txt文件

	char str[10];//保存长度不超过10位的数字（和int表示最大值有关）
	while (!out.eof())
	{
		out >> str;//将读取到的逐个字符存在str中
	}
	sscanf(str, "%d", &num);//将字符串str转换成数字并赋值给num

	out.close();
	return num;
}
void push(stack<int> &s,string p)//入栈函数
{
	s.push(read(p));//将read函数的返回值，即num入栈
}
void pop(stack<int> &s,string p)//出栈函数
{
	int num = -1;
	num=s.top();//栈顶值赋值给num
	s.pop();//栈顶值出栈
	mov(num, p);//mov赋值函数将出栈的num放在.txt文件里
}
void add(string p1, string p2, string p3)//加法函数
{
	int a = read(p1);
	int b = read(p2);
	int c = 0;
	c = a + b;
	mov(c, p3);
}
void sub(string p1, string p2, string p3)//减法函数
{
	int a = read(p1);
	int b = read(p2);
	int c = 0;
	c = a - b;
	mov(c, p3);
}
void mul(string p1, string p2, string p3)//乘法函数
{
	int a = read(p1);
	int b = read(p2);
	int c = 0;
	c = a * b;
	mov(c, p3);
}
void div(string p1, string p2, string p3)//除法函数
{
	int a = read(p1);
	int b = read(p2);
	int c = 0;
	c = a / b;
	mov(c, p3);
}
void show(string p3)//输出函数
{
	cout << read(p3) << endl;
}
void main()
{
	stack<int> s;//建立栈s
	string co;//即将输入的命令co
	while (1)//永久循环
	{
		getline(cin,co);//输入co
		string firstname(co.substr(0, 3));//字符串截取前三位，以此分辨指令
		if (firstname == "mov")
		{
			int num = -1;
			string ex(co.substr(4, co.length()));//处理命令后面的具体信息
			string nums, p;//数字和地址
			istringstream is(ex);
			is >> nums >> p;//这两步是按照空格分割字符串并分别赋值
			stringstream stream(nums);//字符串转数字
			stream >> num;
			mov(num, p);
			//下同
		}
		else if (firstname == "pus")
		{
			string p(co.substr(5, co.length()));
			push(s, p);
		}
		else if (firstname == "pop")
		{
			string p(co.substr(4, co.length()));
			pop(s, p);
		}
		else if (firstname == "add")
		{
			string ex(co.substr(4, co.length()));
			string p1, p2, p3;
			istringstream is(ex);
			is >> p1 >> p2 >> p3;
			add(p1, p2, p3);
		}
		else if (firstname == "sub")
		{
			string ex(co.substr(4, co.length()));
			string p1, p2, p3;
			istringstream is(ex);
			is >> p1 >> p2 >> p3;
			sub(p1, p2, p3);
		}
		else if (firstname == "mul")
		{
			string ex(co.substr(4, co.length()));
			string p1, p2, p3;
			istringstream is(ex);
			is >> p1 >> p2 >> p3;
			mul(p1, p2, p3);
		}
		else if (firstname == "div")
		{
			string ex(co.substr(4, co.length()));
			string p1, p2, p3;
			istringstream is(ex);
			is >> p1 >> p2 >> p3;
			div(p1, p2, p3);
		}
		else if (firstname == "sho")
		{
			string p(co.substr(5, co.length()));
			show(p);
		}
	}
}