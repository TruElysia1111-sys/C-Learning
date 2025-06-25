#include <iostream>
#include"11_add.h" // 引入头文件
using namespace std;

// 定义函数
int add(int a, int b) {
	// 函数体
	// 计算两个数的和
	int sum = a + b;
	// 返回结果
	return sum; // return a+b;
}

// 函数的分文件编写
//		函数的声明放在头文件中
//		函数的定义放在源文件中
//		函数的调用放在主函数中
// 步骤：
//		1. 创建头文件，命名为函数名.h
//		2. 创建源文件，命名为函数名.cpp
//		3. 在头文件中声明函数
// 		4. 在源文件中定义函数
//		5. 在源文件中include头文件，#include "头文件.h"		自定义的头文件需要加双引号
// 		6. 在主函数中include头文件，#include "头文件.h"，在主函数中就可以调用函数 
// 头文件的格式：
//         .h文件