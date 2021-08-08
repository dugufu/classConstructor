#include <iostream>
#include <fstream>
using namespace std;


void test01() {
	ofstream ofs;
	ofs.open("text.txt", ios::out);
	ofs << "ccr" << endl;
	ofs << "10" << endl;
	ofs << "13" << endl;
	ofs.close();

}

int main() {
	test01();
}