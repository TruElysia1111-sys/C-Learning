#include <iostream>
using namespace std;
int main2() {
    //std::cout << "Hello, World!" << std::endl;
    // new操作符
    // 基本语法： new 类型名

    // 开辟内存，new返回的是指针
    int *p = new int;
    cout <<"p = " << p << endl;

    int *p2 = new int(100); // 括号里可以传值
    cout << "p2 = " << p2 << endl;
    cout <<"*p2 = " << *p2 << endl; // 输出100

    // 开辟内存之后，如果想释放内存，使用delete
    delete p2;      // 释放内存
    //cout <<"删除p2之后，*p2 = " << *p2 << endl; // 野指针

    // 开辟数组内存
    int *p3 = new int[5];  // 创建一个大小为5的整型数组
    for (int i = 0; i < 5; ++i) {
        p3[i] = i;
    }
    cout << "p3 = " << p3 << endl;
    for (int i = 0; i < 5; ++i) {
        cout<<"p[i] = " << p3[i] << " ";
    }
    cout << endl;
    delete []p3;    // 释放数组内存
    //cout <<p3<< endl;  // 野指针


    system("pause");
    return 0;
}