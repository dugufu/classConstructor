#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// 
// class Person {
// 
// public:
// 
// 	char m_name[64];
// 	int m_age;
// };
// 
// void test01() {
// 	ofstream ost("person.txt", ios::out | ios::binary);
// 
// 	Person p = { "ccr", 18 };
// 	ost.write((const char*)&p, sizeof(p));
// 	ost.close();
// }
// 
// void test02() {
// 	ifstream ifs;
// 	ifs.open("person.txt", ios::in | ios::binary);
// 	if (! ifs.is_open())
// 	{
// 		cout << "Failed" << endl;
// 		return;
// 	}
// 		Person p;
// 		ifs.read((char*)&p, sizeof(p));
// 
// 		cout << "name :" << p.m_name << endl;
// 		cout << "age :" << p.m_age << endl;
// 
// 		ifs.close();
// 	
// }
// 
// int main() {
// 	//test01();
// 	test02();
// }