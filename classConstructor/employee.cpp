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
	ReadFile(&emp);
	

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
			ReOrdering(&emp);
			break;
		case 7:
			DeleteAllData(&emp);
			break;
		default:
			break;
		}
	}
}

//function delete all data
void DeleteAllData(Employee_level* emp)
{
	char tempChar;

jump:
	cout << "Are you sure to clean up your employee data record ? ( y / n )" << endl;
	cin >> tempChar;
	if (tempChar == 'y') {
		emp->m_employee_id = 0;
		ofstream ofs(FileName, ios::trunc);
		ofs.close();

		cout << "Data clean up !" << endl;
	}
	else if (tempChar == 'n') {
		cout << "Exit to main menu ...." << endl;
	}
	else {
		cout << "Please enter only 'y' or 'n' " << endl;
		goto jump;
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
		char e_name[24];
		int position;
		for (int i = 0; i < num; i++)
		{
			jump_name:
			cout << "Enter Employee " << i + 1 << " name :" << endl;
			cin.ignore();
			cin.getline(e_name, 24);
			if (e_name != "")
			{
				cout << "Enter Employee " << i + 1 << " position : ( 0 = Boss 1 = Manager 2 = Employee )" << endl;
				checkIntInputType(&position);
				emp_lv->personArray[emp_lv->m_employee_id].m_name = e_name;
				emp_lv->personArray[emp_lv->m_employee_id].m_position = position;
				emp_lv->m_employee_id++;
				emp_lv->personArray[emp_lv->m_employee_id - 1].m_id = emp_lv->m_employee_id;

				//write into text.txt
				SaveFile(emp_lv);

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
			cout<< "Employee ID :"<< emp_lvl->personArray[i].m_id << "\tName : " << emp_lvl->personArray[i].m_name << "\t\t Position : "<< getPosition(&emp_lvl->personArray[i].m_position) << "\t\Duty : ";
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
void SearchEmployee(Employee_level* emp_lvl, int deleteStatus, int editStatus) {
	string status_string = "search";
	if (deleteStatus == 1) { status_string = "delete"; }
	if (editStatus == 1) { status_string = "edit"; }

	
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
						else if (editStatus == 1) //edit employee by id
						{
							char edit_name[24];
							int edit_position;
							cout << "Editing this employee details  ( " << emp_lvl->personArray[i].m_name << " )" << endl;
							cout << "Enter your new name: ";
							cin.ignore();
							cin.getline(edit_name, 24);


							cout << "Enter New Position :  ( 0 = boss 1 = manager 2 = employee )" << endl;
							checkIntInputType(&edit_position);
							emp_lvl->personArray[i].m_name = edit_name;
							emp_lvl->personArray[i].m_position = edit_position;
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
					else if (editStatus == 1) //edit employee by name
					{
						char edit_name[24];
						int edit_position;
						cout << "Editing this employee details  ( " << emp_lvl->personArray[i].m_name << " )" << endl;
						

						cout << "Enter your new name: ";
						cin.ignore();
						cin.getline(edit_name, 24);
// 					
						cout << "Enter New Position :  ( 0 = boss 1 = manager 2 = employee )" << endl;
						checkIntInputType(&edit_position);
						emp_lvl->personArray[i].m_name = edit_name;
						emp_lvl->personArray[i].m_position = edit_position;
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
	SaveFile(emp);
}

// Edit
void EditEmployeeDetails(Employee_level* emp) {
	SearchEmployee(emp, 0, 1); // 0 deletestatus = false editstatus = true
}

//Reordering
void ReOrdering(Employee_level* emp_lvl) {
	if (emp_lvl->m_employee_id > 0)
	{
		int num;
		cout << "Press 1 for order sequences" << endl;
		cout << "Press 2 for reverse sequences" << endl;
		checkIntInputType(&num, 1);
		if (num == 1) //ordering sequences
		{
			for (int i = 0; i < emp_lvl->m_employee_id; i++)
			{
				for (int j = 1 + i; j < emp_lvl->m_employee_id; j++)
				{
					if (emp_lvl->personArray[i].m_id > emp_lvl->personArray[j].m_id)
					{
						//store temp data
						int temp_id = emp_lvl->personArray[j].m_id;
						int temp_pos = emp_lvl->personArray[j].m_position;
						string temp_name = emp_lvl->personArray[j].m_name;

						//swap value
						emp_lvl->personArray[j].m_id = emp_lvl->personArray[i].m_id;
						emp_lvl->personArray[j].m_name = emp_lvl->personArray[i].m_name;
						emp_lvl->personArray[j].m_position = emp_lvl->personArray[i].m_position;

						//swap value step 2
						emp_lvl->personArray[i].m_id = temp_id;
						emp_lvl->personArray[i].m_name = temp_name;
						emp_lvl->personArray[i].m_position = temp_pos;
					}
				}
			}
			DisplayDetails(emp_lvl);
		}
		else if (num == 2)//reverse ordering sequences
		{
			for (int i = 0; i < emp_lvl->m_employee_id; i++)
			{
				for (int j = 1 + i; j < emp_lvl->m_employee_id; j++)
				{
					if (emp_lvl->personArray[i].m_id < emp_lvl->personArray[j].m_id)
					{
						//store temp data
						int temp_id = emp_lvl->personArray[j].m_id;
						int temp_pos = emp_lvl->personArray[j].m_position;
						string temp_name = emp_lvl->personArray[j].m_name;

						//swap value
						emp_lvl->personArray[j].m_id = emp_lvl->personArray[i].m_id;
						emp_lvl->personArray[j].m_name = emp_lvl->personArray[i].m_name;
						emp_lvl->personArray[j].m_position = emp_lvl->personArray[i].m_position;

						//swap value step 2
						emp_lvl->personArray[i].m_id = temp_id;
						emp_lvl->personArray[i].m_name = temp_name;
						emp_lvl->personArray[i].m_position = temp_pos;
					}
				}
			}
			DisplayDetails(emp_lvl);
		}
		}else 
		{
			cout << "No data found" << endl;

		}
	};

//*****************************************************************************************************************************************************************************************
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
			cout << "Error : Enter only number" << endl;
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

string getPosition(int* position) {
	
	string s_position;
	if (*position == 0) {
		s_position = "Boss";
		return  s_position;
	}else if (*position == 1) {
		s_position = "Manager";
		return s_position;
	}else {
		s_position = "Employee";
		return s_position;
	}
}

//Save file
void SaveFile(Employee_level * emp) {
	ofstream ofs;
	ofs.open(FileName, ios::out);

	for (int i = 0; i < emp->m_employee_id; i++)
	{
		ofs << emp->personArray[i].m_id << " "
			<< emp->personArray[i].m_name << " "
			<< emp->personArray[i].m_position << endl;
	}
	ofs.close();
}

//read file
void ReadFile(Employee_level* emp) {
	bool Is_file_Exists = true;
	bool Is_file_data = true;
	ifstream ifs;
	ifs.open(FileName, ios::in);
	//document no found
	if (!ifs.is_open())
	{
		cout << "No document exists" << endl;
		emp->m_employee_id = 0;
		Is_file_Exists = false;
		Is_file_data = false;
		ifs.close();

	};
	
	//document found but no data exists
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "No data exists" << endl;
		emp->m_employee_id = 0;
		Is_file_Exists = true;
		Is_file_data = false;
		ifs.close();
	}

	//document exists and use data
	if (Is_file_Exists == true && Is_file_data == true)
	{
		ifstream ifsfile;
		ifsfile.open(FileName, ios::in);
		int m_id;
		string m_name;
		int position;
		int emp_num = 0;

		while (ifsfile >> m_id && ifsfile >> m_name && ifsfile >> position)
		{

			emp->personArray[emp_num].m_name = m_name;
			emp->personArray[emp_num].m_position = position;
			emp->personArray[emp_num].m_id = m_id;
			emp_num++;

		}
		
		emp->m_employee_id = emp_num;
		cout << "Current employee numbers :" << emp_num << endl;
	}
	
	
	ifs.close();
}
