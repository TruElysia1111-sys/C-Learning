#include<iostream>
#include<string>
using namespace std;

/*
string 本质是一个类
内部封装了char*，是一个char*型的容器
str.size()可以获得string的长度

内部封装了一些成员方法：
	find，copy，delete，replace，insert等
*/

/*
构造函数：
string();					创建一个空的字符串
string(const char*s)		使用字符串s初始化
string(const string &str)	使用一个string对象初始化另一个string对象
string(int n,char c)		使用n个字符c初始化
*/
void test02_01() {
	// 默认构造
	string s1;
	// 使用字符串s初始化
	const char* str = "Hello world";
	string s2(str);
	cout << "使用字符串初始化，s2 = " << s2 << endl;
	// 使用一个string对象初始化另一个string对象
	string s3(s2);
	cout << "使用一个string对象初始化另一个string对象，s3 = " << s3 << endl;
	// 使用n个字符c初始化
	string s4(10, 'a');
	cout << "使用n(10)个字符c(a)初始化， s4 = " << s4 << endl;
}

/*
字符串赋值操作：
string& operator=(const char *s)		char*类型字符串赋值给当前字符串
string& operator=(const string &s)		把字符串s赋值给当前字符串
string& operator=(char c)				字符赋值给当前的字符串
string& assign(const char *s)			把字符串s赋值给当前字符串
string& assign(const char *s, int n)	把字符串s的前n个字符赋值给当前字符串
string& assign(const string &s,int n)	从第n位开始，把字符串s赋给当前字符串
string& assign(int n, char c)			用n个字符c赋给当前字符串
*/
void test02_02() {
	// string& operator=(const char* s)		char* 类型字符串赋值给当前字符串
	string str1;
	str1 = "HEllO WORLD";
	cout << "str1 = " << str1 << endl;
	// string& operator=(const string & s)		把字符串s赋值给当前字符串
	string str2;
	str2 = str1;
	cout << "str2 = " << str2 << endl;
	// string& operator=(char c)				字符赋值给当前的字符串
	string str3;
	str3 = 'a';
	cout << "str3 = " << str3 << endl;
	// string& assign(const char* s)			把字符串s赋值给当前字符串
	string str4;
	str4.assign("HELLO C++");
	cout << "str4 = " << str4 << endl;
	// string& assign(const char * s, int n)	把字符串s的前n个字符赋值给当前字符串
	string str5;
	str5.assign("Hello C++", 5);
	cout << "str5 = " << str5 << endl;
	// string& assign(const string & s, int n)	从第n位开始，把字符串s赋给当前字符串
	string str6;
	str6.assign(str4, 6);
	cout << "str6 = " << str6 << endl;
	// string& assign(int n, char c)			用n个字符c赋给当前字符串
	string str7;
	str7.assign(5, 'a');
	cout << "str7 = " << str7 << endl;
}

/*
字符串拼接：
	+=
	append()
*/
void test02_03() {
	string str1 = "Elysia";
	string str1_1 = ".....";
	string str2 = "Kiana";
	string str2_1 = "Kaslana";
	// += 
	str1 += ':';		// 追加字符
	str1 += "爱莉希雅";	// 追加字符串
	str1 += str1_1;		// 追加字符串
	cout << "str1 = " << str1 << endl;
	// append
	str2.append(str2_1);	// 追加字符
	cout << "str2 = " << str2 << endl;
	str2.append("!!!!abcdefg", 4);	// 追加字符的前n个
	cout << "str2 = " << str2 << endl;
	str2.append("<<Otto>>");
	cout << "str2 = " << str2 << endl;
	str2.append("0123456789",1,3 );	// 追加start位开始的n位
	cout << "str2 = " << str2 << endl;
}
/*
查找，替换
find
rfind
replace
*/
void test02_04() {
	string str1 = "abcdefghijklmnopqrstuvwxyz----abcdefghijklmnopqrstuvwxyz";

	// find( s, pos, n)	从pos位置开始找，找n个字符，返回s第一次出现的位置
	int b = str1.find('b');	// 查找b元素第一次出现的位置，若不存在，返回-1
	cout << "b的位置是" << b + 1 << endl;
	int rb = str1.rfind('b'); // rfind和find---> rfind从右往左查找
	cout << "b的位置是" << rb + 1 << endl;
}
void test02_05() {
	string str1 = "abcdefg";

	// replace( pos,n,s) 从pos位置开始的第n个字符替换为s
	str1.replace(0,7,"ABCDEFG");	// 理解成word中的选中然后粘贴
	cout << str1 << endl;
}
/*
字符串比较，比较ASCII码
 = 返回0
 > 返回1
 < 返回-1
*/
void test02_06() {
	string str1 = "abc";
	string str2 = "ABC";
	
	int rst1 = "abc" == str1;
	cout << "abc == str1 ? " << rst1 << endl;
	int rst2 = str1 > str2;
	cout << "str1 > str2 ?" << rst2 << endl;
	int rst3 = str1 < str2;
	cout << "str1 < str2 ?" << rst3 << endl;
	// 使用compare函数
	// compare比较的方式是逐位比较字符串的ASCII值
	cout << " = 返回0;> 返回1;< 返回 - 1" << endl;
	cout << "str1 compare str2????" << str1.compare(str2) << endl;
}
/*
字符存取
char[]
char at()
*/
void test02_07() {
	string str1 = "abcdefg";
	str1[0] = 'A';	// 存取
	cout << "str1 = " << str1 << endl;
	cout << "str1[0] = " << str1.at(0) << endl;
}
/*
插入和删除
insert(pos,string)	在指定pos位置插入字符串
insert(pos,n,char)	在指定pos位置插入n个字符
erase(pos,n)		在pos位置删除n个字符
*/
void test02_08() {
	string str1 = "abcdefghi";
	str1.insert(0, "ASD");
	cout << "str1 = " << str1 << endl;
	str1.insert(0, 2, 'Q');
	cout << "str1 = " << str1 << endl;
	str1.erase(0, 5);
	cout << "str1 = " << str1 << endl;
}
/*
子串
substr(pos,n) 从pos位置开始的n个字符作为子串
*/
void test02_09() {
	string str1 = "Elysia11111";
	string substr = str1.substr(0, 6);
	cout << "str1截取的子串是:" << substr << endl;
}
int main01() {
	// 构造
	cout << "构造" << endl;
	test02_01();
	cout<< endl << endl;
	// 赋值
	cout << "赋值" << endl;
	test02_02();
	cout << endl << endl;
	// 拼接
	cout << "拼接" << endl;
	test02_03();
	cout << endl << endl;
	// 查找
	cout << "查找" << endl;
	test02_04();
	cout << endl << endl;
	// 替换
	cout << "替换" << endl;
	test02_05();
	cout << endl << endl;
	// 比较
	cout << "比较" << endl;
	test02_06();
	cout << endl << endl;
	// 存取
	cout << "存取" << endl;
	test02_07();
	cout << endl << endl;
	// 插入和删除
	cout << "插入和删除" << endl;
	test02_08();
	cout << endl << endl;
	// 子串
	cout << "子串" << endl;
	test02_09();
	cout << endl << endl;
	return 0;
}

