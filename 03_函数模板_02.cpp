#include<iostream>
using namespace std;

/*
注意事项：
	数据类型T要一样
	数据类型T存在
	函数中必须要使用T
*/

/*
利用函数模板封装一个排序的函数，对不同数据类型数组进行排序
从大到小
选择排序
*/

// 交换的模板
template<class T>
void Swap(T& a, T& b) {
	T temp = a;
	a = b;
	b = a;
}

// 选排的模板
template<class T>
void selectSort(T arr[], int len) {
	for (int i = 0; i < len; i++){
		int max = i;	//	默认最大值
		for (int j = i + 1; j < len; j++) {
			if (arr[max] < arr[j]){
				max = j;	// 更新最大值
			}
		}
		if (max != i) {
			// 交换
			Swap(arr[max],arr[i]);
		}
	}
}


void test03_01() {
	// char数组
	char charArr[] = "dajsghtrsacw";
	int charlen = sizeof(charArr) / sizeof(char);

	selectSort(charArr,charlen);
	cout << "排序后的charArr是：";
	for (int i = 0; i < charlen; i++) {
		cout << charArr[i] << " ";
	}
	cout << endl;

	// int数组
	int intArr[] = {7,5,1,7,3,2,7,6,1,4};
	int intlen = sizeof(intArr) / sizeof(int);

	selectSort(intArr, intlen);
	cout << "排序后的intArr是：";
	for (int i = 0; i < intlen; i++) {
		cout << intArr[i] << " ";
	}
	cout << endl;
}

int main03() {

	test03_01();
	system("pause");
	return 0;
}

/*
普通函数和模板函数的区别：
	
普通函数可以发生隐式数据类型转换

模板函数如果是自动类型推导：无法发生隐式数据类型转换
模板函数如果是显式类型指定：可以发生隐式数据类型转换

如果普通函数和函数模板都可以实现： 优先调用普通函数
可以通过空模板参数列表来强制调用函数模板
		函数名<>()			强制调用函数模板
函数模板可以发生重载
如果函数模板可以产生更好的匹配，优先使用函数模板


模板特化：则需要具体化方式做特殊实现
template<> 返回类型 函数名(自定义数据类型）{
	// 相当于当数据类型是自定义的数据类型时，走这段代码，即给特殊的数据类型走了后门
}
*/
