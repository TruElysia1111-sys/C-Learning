#include <iostream>
using namespace std;

// 重载1
void func() {
    cout << "func()" << endl;
}

void func(int a) {   // 参数列表不同
    cout << "func(int a)" << endl;
}


// 重载2
void fun(int& a) {
    cout << "fun(int& a)" << endl;
}

void fun(const int& a) {
    cout << "fun(const int& a)" << endl;
}

// 重载3
void f0(int a) {
    cout << "f(int a)" << endl;
}

void f0(int a, int b = 10) {
    cout << "f(int a = 10)" << endl;
}


int main() {
    //std::cout << "Hello, World!" << std::endl;
    // 函数重载：
    // 同一个函数名，不同的参数列表，可以定义多个函数, 提高函数的复用性
    // 参数列表不同： 参数个数，参数顺序

    // 条件：
    // 1. 函数名相同,在同一个作用域下
    // 2. 参数列表不同
    // 3. 返回值类型可以相同，也可以不同
    // 4. 函数体可以相同，也可以不同
    // 5. 函数重载的函数名，不能和全局变量重名
    // 6. 函数重载的函数名，不能和类成员函数重名
    // 7. 函数重载的函数名，不能和类重名
    // 8. 函数重载的函数名，不能和枚举重名
    // 9. 函数重载的函数名，不能和结构体重名
    // 10. 函数重载的函数名，不能和typedef重名
    func();
    func(10);

    // 函数重载的注意事项：
    // 1. 引用作为函数重载的条件
    // 
    cout << "-------------------------引用作为函数重载的条件" << endl;
    int a = 10;
    fun(a);
    fun(10);
     
    // 2. 函数重载遇到默认参数
    //
    cout << "-------------------------函数重载遇到默认参数" << endl;
    int b = 10;
    //f0(b);        // 报错：二义性，函数重载不要写默认参数
    //f0(b);
    system("pause");
    return 0;
}