#include <iostream>
using namespace std;



int main15() {
    //std::cout << "Hello, World!" << std::endl;

    // 结构体
    // 自定义的数据类型
    // 允许用户储存不同的类型的数据，不同的变量
    
    cout << "-----------------------------------------结构体的定义和使用" << endl;
    // 定义语法：
    /*
        struct 结构体名 {
            成员1;    // 属性
            成员2;
            ...
        };
    */
    struct Student {
        string name;    // 姓名
        string gender;  // 性别
        int age;        // 年龄
        float score;    // 成绩
    };
    // 使用结构体
    cout << "创建具体的" << endl;
    /*
        创建结构体变量：
        struct 结构体名 变量名;
    */
    /*  1. struct 结构体名 变量名
        2. struct 结构体名 变量名 = {成员1, 成员2, ...};   
        3. 在定义结构体时，可以初始化结构体变量
            struct 结构体名 {
                数据类型 成员1 = 值1;
                数据类型 成员2 = 值2;
                ...
            } 变量名;                 // 在定义结构体时，顺便创建一个变量
    */
    cout << "1. struct 结构体名 变量名"<<endl;
    struct Student stu1;
    stu1.name = "Elysia";
    stu1.gender = "female";
    stu1.age = 18;
    stu1.score = 100.0;
    cout << "\tstu1.name = \t" << stu1.name << endl;
    cout << "\tstu1.gender = \t" << stu1.gender << endl;
    cout << "\tstu1.age = \t" << stu1.age << endl;
    cout << "\tstu1.score = \t" << stu1.score << endl;
    
    cout << "2.struct 结构体名 变量名 = {成员1, 成员2, ...};" << endl;
    struct Student stu2 = {"Kiana", "female", 16, 60.0};
    cout << "\tstu2.name = \t" << stu2.name << endl;
    cout << "\tstu2.gender = \t" << stu2.gender << endl;
    cout << "\tstu2.age = \t" << stu2.age << endl;
    cout << "\tstu2.score = \t" << stu2.score << endl;

    cout<< "3. 在定义结构体时，可以初始化结构体变量" << endl;  // 不建议使用
    struct Student1 {
        string name = "MEI";
        string gender = "female";
        int age = 18;
        float score = 100.0;
    } stu3;
    cout << "\tstu3.name = \t" << stu3.name << endl;
    cout << "\tstu3.gender = \t" << stu3.gender << endl;
    cout << "\tstu3.age = \t" << stu3.age << endl;
    cout << "\tstu3.score = \t" << stu3.score << endl;
    // 在C++中，变量的创建可以省略struct，但是结构体定义时，struct不可以省略
    // Student stu4;   // 相当于 struct Student stu4;
    cout << endl;


    // 结构体数组
    cout << "-----------------------------------------结构体数组" << endl;
    // 将自定义的结构体放入到数组中方便维护
    // 创建自定义结构体
    struct Teacher {
        string name;
        string gender;
        int age;
    };
    // 创建结构体数组
    Teacher t[3] = {
        {"Hemiko", "female", 38},
        {"Fu_Hua", "female", 18},
        {"Natasha", "female", 38}
    };
    // 数组创建后也可以改变值
    t[1].name = "TruElysia";
    // 遍历数组
    for (int i = 0; i < 3; i++) {
        cout << "\tTeacher[" << i << "].name = " << t[i].name << "\t";
        cout << "\tTeacher[" << i << "].gender = " << t[i].gender << "\t";
        cout << "\tTeacher[" << i << "].age = " << t[i].age << "\t";
        cout << endl;
    }
    cout << endl;

    // 结构体指针
    cout << "-----------------------------------------结构体指针" << endl;
    // 通过结构体指针访问结构体中的成员
    // 创建结构体变量
    struct Person {
        string name;
        string gender;
        int age;
    };
    Person p1 = {"LiNan", "Male", 22};
    // 创建结构体指针,通过指针指向结构体变量
    Person *p = &p1;  // struct Person *p;
    // 通过指针访问结构体成员 p->成员
    cout << "\tp->name = " << p->name << "\t";
    cout << "\tp->gender = " << p->gender << "\t";
    cout << "\tp->age = " << p->age << "\t";
    cout << endl << endl;

    // 结构体嵌套
    cout << "-----------------------------------------结构体嵌套" << endl;
    // 结构体中的成员可以是另一个结构体
    struct Individual {
        string name;
        string gender;
        int age;
        struct Father{      // 嵌套结构体 可以在内部定义，也可以在外部定义
            string name;
            int age;
        } Father;
        struct Mother{      // 嵌套结构体 可以在内部定义，也可以在外部定义
            string name;
            int age;
        }Mother;
    };
    // 创建结构体变量
    Individual i1 = {"LiNan", "male", 23, {"LFF", 22}, {"__", 22}};
    // 访问结构体成员
    cout << "\ti1.name = " << i1.name << "\t";
    cout << "\ti1.gender = " << i1.gender << "\t";
    cout << "\ti1.age = " << i1.age << "\n";
    cout << "\ti1.Father.name = " << i1.Father.name << "\t";
    cout << "\ti1.Father.age = " << i1.Father.age << "\n";
    cout << "\ti1.Mother.name = " << i1.Mother.name << "\t";
    cout << "\ti1.Mother.age = " << i1.Mother.age << "\t";
    cout << endl << endl;


    
    system("pause");
    return 0;
}

