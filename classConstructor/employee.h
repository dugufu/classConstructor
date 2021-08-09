#pragma once
#include <iostream>
using namespace std;


class boss {
public:
	virtual void duty() {
		cout << "Boss assigned tasks to manager" << endl;
	}
};

class manager : public boss {
public:
	void duty() {
		cout << "Manager assigned tasks to employee, received tasks from boss" << endl;
	}
};

class employee : public boss {
public:
	void duty() {
		cout << "Employee received tasks from manager" << endl;
	}

};

void ExitProgram(int * num);
void showMenu();
void DisplayDetails();
void DeleteEmployee();
void EditEmployeeDetails();
void SearchEmployee();
void ReOrdering();
void DeleteAllData();

//other tools
int checkVarIsInt(int* numInt);//check for intType 1= true 0 = false