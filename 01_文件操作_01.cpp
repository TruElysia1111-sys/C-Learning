# include<iostream>
using namespace std;
# include<string>
// 需要包含头文件<fstream>
# include<fstream>

/*
文本文件：	以ASCII码形式存储在计算机中
二进制文件：文件以文本二进制形式存储在计算机中（一般不能直接读懂）
*/

/*
ofstream:	写操作
ifstream:	读操作
fstream:	读写操作
*/

/*
步骤：
	1. 包含头文件 #include<fstream>
	2. 创建流对象		oftream ofs						ifstream ifs
	3. 打开文件			ofs.open("文件路径",打开方式)	ifs.open("文件路径",打开方式)
	4. 写数据			ofs<<"写入的数据";				四种读取方式
	5. 关闭文件
*/
/*
打开方式：
	ios::in		读文件
	ios::out	写文件
	ios::ate	初始位置: 文件末尾
	ios::app	追加方式写文件
	ios::trunc	如果文件存在先删除，再重新创建
	ios::binary	二进制方式

打开方式可以配合使用，利用|操作符	ofs.open("路径",ios::binary|ios::out)

*/

void test01() {
	// 写文件
	ofstream ofs; // 创建流对象

	ofs.open("01_test01.txt", ios::out); // 打开文件

	ofs << "姓名: Elysia" << endl << "年龄: 16" << endl << "性别: 女" << endl; //写文件

	ofs.close(); // 关闭文件
}

void test02() {
	// 读文件，注意文件的编码格式
	/*
		读数据：4种方式
	*/
	ifstream ifs; // 创建流对象
	// 1.
	cout << "第一种方式-------------------------------" << endl;

	ifs.open("01_test02.txt", ios::in); // 打开文件（读操作
	if (!ifs.is_open()) {
		// 判断是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	// 读操作
	char buf1[1024] = { 0 };
	while (ifs >> buf1) { // 读到结尾时，返回False（无法读汉字
		cout << buf1 << endl;
	}
	ifs.close();

	// 2.
	cout << "第二种方式-------------------------------" << endl;

	ifs.open("01_test02.txt", ios::in); // 打开文件（读操作
	if (!ifs.is_open()) {
		// 判断是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	// 读操作
	char buf2[1024] = { 0 };
	while (ifs.getline(buf2, sizeof(buf2))) {	// getline(返回值存储地址，最大空间长度)
		cout << buf2 << endl;
	}
	ifs.close();

	// 3.
	cout << "第三种方式-------------------------------" << endl;
	ifs.open("01_test02.txt", ios::in); // 打开文件（读操作
	if (!ifs.is_open()) {
		// 判断是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	// 读操作
	string buf3;
	while (getline(ifs, buf3)) {	// getline()函数需要包含头文件<string>
		cout << buf3 << endl;
	}
	ifs.close();

	// 4. 不推荐
	cout << "第四种方式-------------------------------" << endl;
	ifs.open("01_test02.txt", ios::in); // 打开文件（读操作
	if (!ifs.is_open()) {
		// 判断是否打开成功
		cout << "文件打开失败" << endl;
		return;
	}
	char c;
	while ((c = ifs.get()) != EOF) {	// 一个一个字符读，直到读到EOF(End of File 文件结束标志)
		cout << c;
	}
	ifs.close();
}
int main01() {

	test01();	// 写文件

	test02();	// 读文件
	return 0;
}

