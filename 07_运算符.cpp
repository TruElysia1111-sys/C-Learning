#include <iostream>
using namespace std;
int main7() {
    //std::cout << "Hello, World!" << std::endl;

    // 运算符：
    //      1. 算术运算符
    //      2. 赋值运算符
    //      3. 比较运算符
    //      4. 逻辑运算符


    cout << "--------------------------------------------------------------------------------------------------算数运算符" << endl;
    /*
        1. 算数运算符：
            + - * / %       加减乘除取余      
                两个整数相除只保留整数部分
            ++ ++ -- --     前置递增，后置递增，前置递减，后置递减
    */
    
    int a = 5;
    int b = 2;
    float f1 = 5.0;
    float f2 = 3.1;

    cout << "a+b = " << a + b << endl;
    cout << "a-1 = " << a - b << endl;
    cout << "a*b = " << a * b << endl;
    cout << "a/b = " << a / b << endl;  // 整数相除只保留整数部分
    cout << "a%b = " << a % b << endl;
    // cout << "f1%f2 = " << f1 % f2 << endl;  // 取模运算只能在整数上使用
    cout << "两个小数相除,f1/f2 = " << f1 / f2 << endl;

    int c = 1;
    int d = 1;
    cout << "前置递增c，先增， c ==" << ++c << endl;   // 2
    cout << "后置递增d，后增， d ==" << d++ << endl;   // 1
    cout << "后置递增之后d已经+1， d ==" << d << endl; // 2

    cout << "--------------------------------------------------------------------------------------------------赋值运算符" << endl;
    /*
        2. 赋值运算符：
            = += -= *= /= %=
    */

    int a1 = 17;

    a1 += 2;  // a1 = a1 + 2 = 19
    cout << "a1 += 2 是 " << a1 << endl;
    a1 /= 2;  // a1 = a1 / 2 = 9
    cout << "a1 /= 2 是 " << a1 << endl;
    a1 %= 4;  // a1 = a1 % 4 = 1
    cout << "a1 %= 2 是 " << a1 << endl;
    a1 *= 4;  // a1 = a1 * 4 = 4
    cout << "a1 *= 4 是 " << a1 << endl;

    cout << "--------------------------------------------------------------------------------------------------比较运算符" << endl;
    /*
        3. 比较运算符：
            == != < > <= >=
            返回1（true） 和 0（false）
    */

    int a2 = 1;
    int b2 = 7;

    cout << "a2 > b2 ?" << (a2 > b2) << endl;  // 0
    cout << "a2 == b2 ?" << (a2 == b2) << endl;  // 0
    cout << "a2 < b2 ?" << (a2 < b2) << endl;  // 1

    cout << "--------------------------------------------------------------------------------------------------逻辑运算符" << endl;
    /*
        4. 逻辑运算符：
            ! 非
            && 与
            || 或
    */

    cout << "非 true = " << (!true) << endl;
    cout << "true 与 true = " << (true && true) << endl;
    cout << "false 与 true = " << (false && true) << endl;
    cout << "true 或 true = " << (true || true) << endl;
    cout << "false 或 true = " << (false || true) << endl;
    cout << "false 或 false = " << (false || false) << endl;

    system("pause");
    return 0;
}