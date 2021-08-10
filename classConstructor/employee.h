#pragma once
#define MaxEmployee 1000
#include <iostream>
using namespace std;

class Boss {
public:
	virtual void duty() {
		cout << "Boss assigned tasks to manager" << endl;
	}
// 	virtual ~Boss() {
// 		cout << "Boss Deconstrucot Called" << endl;
// 	}
	string m_name;
	int m_position;
		
	
};

class Manager : public Boss {
public:
	void duty() {
		cout << "Manager assigned tasks to employee, received tasks from boss" << endl;
	}
// 	~Manager() {
// 		cout << "Manager Deconstrucot Called" << endl;
// 	}
};

class Employee : public Boss {
public:
	void duty() {
		cout << "Employee received tasks from manager" << endl;
	}
// 	~Employee() {
// 		cout << "Employee Deconstrucot Called" << endl;
// 	}
};

class Employee_level {
public:
	Boss personArray[MaxEmployee];
	int m_employee_id = 0;


};

void ExitProgram(int * num);
void AddNewEmployee(Employee_level * emp);
void showMenu();
void DisplayDetails(Employee_level * emp_lvl);
void DeleteEmployee(Employee_level* emp);
void EditEmployeeDetails(Employee_level * emp);
void SearchEmployee(Employee_level * emp, int deleteStatus = 0);
void ReOrdering();
void DeleteAllData();

//other tools
void checkIntInputType(int* num, int search = 0);
Boss* EnterPosition(int* position);