#include <iostream>
using namespace std;

int func(int a, int b = 10, int c = 20) {
    return a +b +c ;
}

int func2(int a, int b, int) {
    return a + b;
}
int main4() {
    //std::cout << "Hello, World!" << std::endl;
    /*
        函数默认参数：
            语法：
            数据类型 函数名 （参数 = 默认值）{
                函数体
            }

        如果函数声明中写了默认参数，那么在函数实现中就不用写默认参数了。
    */
    cout<<"a=1, func = " << func(1) << endl;
    cout<<"a=1,b=2,c=3, func = " << func(1, 2, 3) << endl;

    cout << endl << endl;
    /*
        函数的占位参数:
        占用参数必须使用
        语法：
            数据类型 函数名（数据类型 参数，数据类型）{
                函数体
            }
    */
    cout <<"a=1,b=2" << func2(1, 2, 3) << endl;

    system("pause");
    return 0;
}