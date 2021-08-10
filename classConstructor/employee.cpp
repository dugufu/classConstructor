#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <string>
#include "employee.h"
using namespace std;


void showMenu() {
	cout << "************************************" << endl;
	cout << "*** 0. Exit Program \t\t ***" << endl;
	cout << "*** 1. Add New Employee \t ***" << endl;
	cout << "*** 2. Display Employee Details  ***" << endl;
	cout << "*** 3. Delete Employee \t\t ***" << endl;
	cout << "*** 4. Edit Employee \t\t ***" << endl;
	cout << "*** 5. Search Employee \t\t ***" << endl;
	cout << "*** 6. ReOrdering Employee \t ***" << endl;
	cout << "*** 7. Delete All Data \t\t ***" << endl;
}


int main() {
	int num = -1;
	int program = -1;
	Employee_level emp;
	while (program != 0)
	{
		system("CLS");
		showMenu();
		cout << "\nEnter Number here" << endl;
		checkIntInputType(&num);
		switch (num)
		{
		case 0:
			ExitProgram(&program);// Exit program
			break;
		case 1:
			AddNewEmployee(&emp);
			break;
		case 2:
			DisplayDetails(&emp);
			break;
		case 3:
			DeleteEmployee(&emp);
			break;
		case 4:
			EditEmployeeDetails(&emp);
			break;
		case 5:
			SearchEmployee(&emp);
			break;
		case 6:
			break;
		case 7:
			break;
		default:
			break;
		}
	}
}

//function 0 
void ExitProgram(int * num) {
	*num = 0;
}
//Add
void AddNewEmployee(Employee_level * emp_lv) {
	jump_to_add_employee:
	cout << "How many employees are u gonna sign?" << endl;
	int num;
	checkIntInputType(&num);

	if (num > 0)
	{
		string e_name;
		int position;
		for (int i = 0; i < num; i++)
		{
			jump_name:
			cout << "Enter Employee " << i + 1 << " name :" << endl;
			cin >> e_name;
			if (e_name != "")
			{
				cout << "Enter Employee " << i + 1 << " position : ( 0 = Boss 1 = Manager 2 = Employee )" << endl;
				checkIntInputType(&position);
				emp_lv->personArray[emp_lv->m_employee_id].m_name = e_name;
				emp_lv->personArray[emp_lv->m_employee_id].m_position = position;
				emp_lv->m_employee_id++;

			}
			else {
				goto jump_name;
			}
		}
	}
	else {
		goto jump_to_add_employee;
	}

}

//display
void DisplayDetails(Employee_level * emp_lvl) {
	if (emp_lvl->m_employee_id > 0)
	{
		for (int i = 0; i < emp_lvl->m_employee_id ; i++)
		{
			Boss* temp_person = EnterPosition(&emp_lvl->personArray[i].m_position);
			cout<< "Employee ID :"<< i + 1 << "\tName : " << emp_lvl->personArray[i].m_name << "\t\tPosition : ";
			temp_person->duty();
			cout << endl;
			delete temp_person;
			temp_person = NULL;

		}
	}
	else {
		cout << "No data found" << endl;

	}
	system("pause");
}


//search
void SearchEmployee(Employee_level* emp_lvl, int deleteStatus) {
	string status_string;
	if (deleteStatus == 1) { status_string = "delete"; }
	else { status_string = "search"; };
	
	cout << "Select one of these options to "<< status_string <<" the data you want" << endl;
	cout << "Option 1 : "<< status_string <<" by employee ID press keyboard 1" << endl;
	cout << "Option 2 : "<< status_string <<" by employee Name press keyboard 2" << endl;
	int num;
	checkIntInputType(&num, 1); // 1 is to search input data with 1 and 2
	if (num == 1)
	{
		cout << "Please Enter employee ID" << endl;
		checkIntInputType(&num);
		if (emp_lvl->m_employee_id > 0)
			{
				for (int i = 0; i < emp_lvl->m_employee_id; i++)
				{
					if ((num - 1) == i)
					{
						if (deleteStatus == 1) // if == 1 delete the employee by emp_id
						{
							for (int j = i ;j < emp_lvl->m_employee_id; j++)
							{
								emp_lvl->personArray[j] = emp_lvl->personArray[j + 1];
							}

							emp_lvl->m_employee_id--;
							cout << "Employee Deleted" << endl;
						}
						else
						{
							Boss* temp_person = EnterPosition(&emp_lvl->personArray[i].m_position);
							cout << "Employee ID :" << i + 1 << "\tName : " << emp_lvl->personArray[i].m_name << "\t\tPosition : ";
							temp_person->duty();
							cout << endl;
							delete temp_person;
							temp_person = NULL;
						}
					}				
				}
			}
			else 
			{
				cout << "Data is empty" << endl;
			}
			system("pause");
			num = 0;
	}

	if (num == 2)
	{
		cout << "Please Enter employee Name" << endl;
		string e_name;
		cin >> e_name;
		if (emp_lvl->m_employee_id > 0)
		{
			for (int i = 0; i < emp_lvl->m_employee_id; i++)
			{
				if (e_name == emp_lvl->personArray[i].m_name)
				{
					if (deleteStatus == 1) // if == 1 delete the employee by emp_id
					{
						for (int j = i; j < emp_lvl->m_employee_id; j++)
						{
							emp_lvl->personArray[j] = emp_lvl->personArray[j + 1];
						}

						emp_lvl->m_employee_id--;
						cout << "Employee Deleted" << endl;
					}
					else {
						Boss* temp_person = EnterPosition(&emp_lvl->personArray[i].m_position);
						cout << "Employee ID :" << i + 1 << "\tName : " << emp_lvl->personArray[i].m_name << "\t\tPosition : ";
						temp_person->duty();
						cout << endl;
						delete temp_person;
						temp_person = NULL;
					}
					
				}
			}
		}
		else
		{
			cout << "No person found" << endl;
		}
		system("pause");
	}
	
}

//delete
void DeleteEmployee(Employee_level* emp) {
	SearchEmployee(emp, 1); //1 is turn on delete status
}


//Extra Func
void checkIntInputType(int * num, int search) {
	if (search == 1)
	{
		while (!(cin >> *num) && *num != 1 && *num != 2) {
			cout << "\nEnter Number Again With 1 or 2" << endl;
			cout << "Error : Enter only number" << endl;;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	else
	{
		while (!(cin >> *num)) {
			cout << "\nEnter Number Again" << endl;
			cout << "Error : Enter only number" << endl;;
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
	}
	
}

Boss * EnterPosition(int * position) {
	Boss* temp_person;
	if (*position == 0)
	{
		temp_person = new Boss;
		return temp_person;
	}
	else if (*position == 1) {
		temp_person = new Manager;
		return temp_person;
	}
	else {
		temp_person = new Employee;
		return temp_person;
	}
}