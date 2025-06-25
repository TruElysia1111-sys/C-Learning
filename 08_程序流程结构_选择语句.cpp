#include <iostream>
using namespace std;
int main8() {
    //std::cout << "Hello, World!" << std::endl;
    /*
        选择结构：   依据条件是否满足，有选择地执行相应功能
            if语句
            switch语句
    */

    cout << "--------------------------------------------------------------------------------------------------if语句" << endl;
    /*
        结构：
            if 条件
            {
                执行语句
            }
            else if 条件
            {
                执行语句
            }
            else
            {
                执行语句
            }
    */
    float score = 0;
    cout << "请输入你的分数:" << endl;
    cin >> score;

    cout << "您的分数是：" << score << endl;
    if (score >= 600)
        cout << "成绩高于600" << endl;
    else if (score >= 500 and score < 600)
        cout << "成绩高于500" << endl;
    else if (score >= 400 and score < 500)
        cout << "成绩高于400" << endl;
    else
        cout << "废物" << endl;
    
    cout << "-----------------------------------------------------------------------------------------------三目运算符" << endl;
    /*
        三目运算符：
            条件 ? 表达式1 : 表达式2
            如果条件为真，执行表达式1，否则执行表达式2
    */
    // 1. 作为执行语句
    score > 300 ? cout << "大于300" << endl: cout << "小于300" << endl;
    // 2. 作为结果赋值给变量
    char level = (score > 500 ? 'A' : 'B');
    cout << "level = " << level << endl;
    // 3. 作为变量
    int a = 10;
    int b = 20;
    (a > b ? a : b) = 30;
    cout << "给较大的一个重新赋值为 a,b = " << a <<"," << b << endl;

    cout << "-------------------------------------------------------------------------------------------------switch语句" << endl;
    /*
        switch语句:  只可以是整型，但是结构清晰，执行效率高
            switch(变量):
            {
                case 结果1:   执行语句; break;
                case 结果2:   执行语句; break;
                case 结果3:   执行语句; break;
                case 结果4:   执行语句; break;
                ...
                default:      执行语句;break;
            }
    */
    switch(score>200)
    {
        case 1:
            cout << "好" << endl;
            break;
        case 0:
            cout << "坏" << endl;

    }

    system("pause");
    return 0;
}