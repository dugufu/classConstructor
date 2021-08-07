#include <iostream>
#include <string>
using namespace std;
// when create a class will create 3 types of constructor 
//1. default constructor
//2. De-constructor
//3. Copy Constructor
// 
// class Person {
// public:
// 	Person()
// 	{
// 		cout << "Default Constructor" << endl;
// 	}
// 	Person(int age, int height)
// 	{
// 		m_height = new int(height);
// 		m_age = age;
// 	}
// 	Person(const Person& p)
// 	{
// 
// 		m_age = p.m_age;
// 		m_height = new int(*p.m_height);
// 		cout << "Copy Constructor" << endl;
// 	}
// 
// 	~Person()
// 	{
// 		if (m_height != NULL)
// 		{
// 			delete m_height; // error
// 			m_height = NULL; //prevent this m_height become wild pointer
// 		}
// 		cout << "De Constructor" << endl;
// 	}
// 	int m_age;
// 	int m_id;
// 	int* m_height;
// private:
// 
// };
// 
// Person test1() {
// 	Person p1;
// 	return p1;
// }
// 
// void Dowork() {
// 	//Person p = test1();
// 	Person p2(12, 160);
// 	Person p3 = Person(p2);
// 	cout << "2 : \n" << *p2.m_height << "\n" << p2.m_age << endl;
// 	cout << "p3 : \n" << *p3.m_height << "\n" << p3.m_age << endl;
// }
// int main() {
// 
// 	Dowork();
// 	return 0;
// };