#include <iostream>
using namespace std;


void swap(int* p1, int* p2) {
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
int main13() {
    //std::cout << "Hello, World!" << std::endl;
    // 指针和函数
    cout << "-------------------------------------------------------指针和函数" << endl;
    int a = 10;
    int b = 20;

    // 交换两个数的值, 函数体外的变量a，b的值也改变了
    // 地址传递可以修改函数体外的值
    swap(&a, &b);   // 传递指针

    // 输出
    cout << "a = " << a << endl;    // 20
    cout << "b = " << b << endl;    // 10 // 交换成功


    system("pause");
    return 0;
}