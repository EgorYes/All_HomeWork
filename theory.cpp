#include <iostream>
using namespace std;

struct MyStruct
{
	char c;
	double d;
};

struct MyStructC
{
	char c;
};

struct MyStructD
{
	double d;
};

struct MyStructA
{

};

struct MyStructB
{
	MyStructA a;

	struct MyStructB* B1;

};

union MyStructF
{
 
	float x,y;

};


MyStruct s;
MyStructC c;
MyStructD d;
MyStructA a;
MyStructB b;
MyStructF sF;

int main() 
{
	//1-2

	cout << sizeof(s) << endl;
	cout << sizeof(c) << endl;
	cout << sizeof(d) << endl;
	//Происходит выравнивание по double, который весит 8, а значит следующее число будет 16

	cout << "" << endl;

	//3

	int i = 7;
	int* pi = &i;
	cout << sizeof(pi) << endl;

	char c = 77;
	char* pc = &c;
	cout << sizeof(pc) << endl;

	float f = 3.44;
	float* pf = &f;
	cout << sizeof(pf) << endl;

	//размер указателя зависит от архитектуры и компилятора. Размер указателя на все типы данных одинаков и определяется архитектурой процессора
	//На 32-битной архитектуре размер указателя обычно составляет 4 байта, а на 64-битной — 8 байт

	cout << "" << endl;

	//4

	cout << c <<" " << static_cast<int>(c) << endl;

	cout << "" << endl;

	//5

	f = f + f;

	i = f;

	cout << i << endl;

	// число округляется до целого в наименьшую сторону и мы теряем часть информации

	cout << "" << endl;
	
	//6-7

	//да

	cout << "" << endl;

	//10

	sF.x = 12.23;

	cout << sF.x << '\t' << sF.y << endl;

	sF.y = 122.23;

	cout << sF.x << '\t' << sF.y << endl;

	MyStructF sF{ 32.23};

	cout << sF.x << '\t' << sF.y << endl;

	//оба значения равны друг другу из-за ограниченной памяти

	return 0;
}
