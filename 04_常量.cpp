#include <iostream>
using namespace std;

/*
	# define 
	const
*/

/* #define 定义宏常量，一般放在文件的上方*/
#define Weekdays 7


int main4() {

	// Weekdays = 14; // 报错，不可修改
	cout << "一周有" << Weekdays << "天" << endl;

	// const 修饰变量  const 数据类型 变量名 = 值
	const int month = 12;  // month也不可修改
	cout << "一年有" << month << "个月" << endl;


	system("pause");
	return 0;
}