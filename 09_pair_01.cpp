#include<iostream>
#include<random>
using namespace std;

int main09() {

	pair<int, string> p1(1, "Elysia");
	cout << p1.first;
	cout << p1.second;

	pair<int, string> p2 = make_pair(2, "Kiana");
	cout << p2.first;
	cout << p2.second;
	return 0;
}