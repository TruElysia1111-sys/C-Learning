#include <iostream>
#include <iomanip> // 保留小数位数


using namespace std;

/*
    数据类型：   给变量分配一个合适的内存空间
    1. 整型
    2. 实型
    3. 字符
    4. 转义字符
    5. 字符串
    6. 布尔型
    7. 数据的输入
*/
int main6() {
    // std::cout << "Hello, World!" << std::endl;

    /*  1 byte = 8 bits
        sizeof关键字：  sizeof(数据类型/变量)
            可以统计数据类型所占的内存大小，单位字节，byte
    */
    cout << "--------------------------------------------------------------------------------------------------------------整数" << endl;
    /*
        1. 整型： 整数类型
            short：  短整形     2字节                 -2^15  到  2^15-1     -32768~32767
            int：    整形       4字节                                       
            long：   长整形     Windows 4字节                               
            long long：长长整形 8字节                                       
    */

    // 如果赋值超过上限，则回到下限
    short num1 = 10;
    int num2 = 10;
    long num3 = 10;
    long long num4 = 10;

    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;
    cout << "num3=" << num3 << endl;
    cout << "num4=" << num4 << endl;

    cout << "short = " << sizeof(short) <<" bytes"<< endl;  // 2 bytes
    cout << "int = " << sizeof(int) << " bytes" << endl;    // 4 bytes
    cout << "long = " << sizeof(long) << " bytes" << endl;  // 
    cout << "long long = " << sizeof(long long) << " bytes" << endl;  // 8 bytes


    cout << "--------------------------------------------------------------------------------------------------------------浮点数" << endl;
    /*
        2. 实型： 浮点类型
            float：  单精度     4字节     7位有效数字
            double： 双精度     8字节     15~16位有效数字
            科学计数法   e3表示10的3次方
    */

    // 一般在小数后面写一个f
    // 编译器默认小数为双精度，加一个f来让编译器按float处理
    float f1 = 3.14159f;

    // 科学计数法
    float f2 = 3e2;     
    float f3 = 3e-4;
    // double
    double d1 = 3.14159265;
    
    // 输出一个小数默认展示6位有效数字
    cout << "float f1 = " << f1 << endl;
    cout << "float f2 = " << f2 << endl;
    cout << "float f3 = " << f3 << endl;
    cout << "double d1 = " << d1 << endl;

    // 保留几位
    cout << setprecision(3) << "保留3位有效数字 setprecision(2): float f1 = " << f1 << endl;  // setprecision(n)是保留n位有效数字
    cout << setiosflags(ios::fixed)  << "保留小数点后3位，setiosflags(ios::fixed): float f1 = " << f1 << endl; // 保留小数点后3位
    //cout << setiosflags(ios::scientific) << "科学计数法，setiosflags(ios::scientific): float f1 = " << f1 << endl; // scientific是科学计数法
    //cout << setiosflags(ios::showpoint) << "显示小数点，setiosflags(ios::showpoint): float f1 = " << f1 << endl; // showpoint是显示小数点
    //cout << setiosflags(ios::showpos) << "显示正负号，setiosflags(ios::showpos): float f1 = " << f1 << endl; // showpos是显示正负号

    cout << "float = " << sizeof(float) << " bytes" << endl;    // 4
    cout << "double = " << sizeof(double) << " bytes" << endl;  // 8

    cout << "--------------------------------------------------------------------------------------------------------------字符型" << endl;
    /*
    3. 字符型
        char：  用单引号，只能写一个字符     1 字节    字符变量在内存中按ASCII编码放入到存储单元
                                                       a: 97    A: 65
    */

    // 常见错误: 使用双引号创建    只能使用一个字符
    char ch1 = 'a';

    cout << "ch1 = " << ch1 << endl;

    cout << "char = " << sizeof(char) << " bytes" << endl;  // 1
    // 使用int强制转换为10进制
    cout << "ch1的ASCII值为:" << int(ch1) << endl;

    cout << "--------------------------------------------------------------------------------------------------------------转义字符" << endl;
    /*
    4. 转义字符
        \a：     警报
        \b：     退格，将当前位置移到前一列
        \f：     换页，将当前位置移到下页开头
        \n：     换行
        \t：     水平制表，跳到下一个TAB位置，一个TAB是8个空格长度，可以整齐地输出数据
        \\：     代表一个\
    */

    cout <<"换行" << "\n" <<"\\n换行了" << endl;
    cout << "输出单斜杠" << "\\" << endl;
    cout << "水平制表符" << "aaa\tworld" << endl;
    cout << "水平制表符" << "aaaa\tworld" << endl;
    cout << "水平制表符" << "aaaaa\tworld" << endl;

    cout << "--------------------------------------------------------------------------------------------------------------字符串类型" << endl;
    /*
    5. 字符串类型
        表示一串字符,使用双引号
        延用C语言：  char 变量名[] = ""
        C++风格：    string 变量名 = ""
    */
    
    char str1[] = "Hello World1";
    string str2 = "Hello World2";

    cout << "str1 = " << str1 << endl;
    cout << "str2 = " << str2 << endl;

    cout << "sizeof(str1) = " << sizeof(str1) << " bytes" << endl;
    cout << "sizeof(str2) = " << sizeof(str2) << " bytes" << endl;

    cout << "--------------------------------------------------------------------------------------------------------------布尔类型" << endl;
    /*
    6. 布尔类型bool
        true：   真，本质是1      1字节
        false：  假，本质是0      1字节

        非0值的bool值是true(1)
    */

    bool b1 = true;
    bool b2 = false;
    
    cout << "b1 = " << b1 << endl;  // 1
    cout << "b2 = " << b2 << endl;  // 0

    cout << "bool内存 = " << sizeof(bool) << " bytes" << endl;

    cout << "--------------------------------------------------------------------------------------------------------------数据的输入" << endl;
    /*
    7. 数据的输入        从键盘获取数据
        cin >> 变量
    */
    int a = 0;
    cout << "请输入整型a" << endl;
    cin >> a;
    cout << "a = " << a << endl;

    float b = 3.14f;
    cout << "请输入浮点型b" << endl;
    cin >> b;
    cout << "b = " << b << endl;

    string c = "abd";
    cout << "请输入字符串型c" << endl;
    cin >> c;
    cout << "c = " << c << endl;

    bool d = true;
    cout << "请输入布尔类型d" << endl;
    cin >> d;
    cout << "d = " << d << endl;

    system("pause");
    return 0;
}