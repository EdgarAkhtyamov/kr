#include <iostream>
#include <vector>

int** memory(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++) {

		array[i] = new int[columns];
	}
	return array;
}

int** randfill(int** array, unsigned rows, unsigned columns){
	for (unsigned i{}; i < rows; i++) {

		for (unsigned j{}; j < columns; j++) {

			array[i][j] = 1 + rand() % 100;

		}
	}
	return array;
}

int** demonstrate(int** array, unsigned rows, unsigned columns) {
	for (unsigned i{}; i < rows; i++)
	{
		for (unsigned j{}; j < columns; j++)
		{
			std::cout << array[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	return 0;
}

void dlt(int** array, unsigned rows) {
	for (unsigned i{}; i < rows; i++)
	{
		delete[] array[i];
	}
	delete[] array;
}

int main_diag(int** array, unsigned rows, unsigned columns) {
	int sum = 0;
	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < columns; j++) {
			if (i == j) {
				sum += array[i][j];
			}
		}
	}
	return sum;
}

struct Employee
{
	std::string name;
	std::string password;
	int id;
};

void addEmp(std::vector <Employee>& employees) {
	Employee newEmployee;
	std::cout << "Enter your name: " << std::endl;
	std::cin >> newEmployee.name;
	std::cout << "Enter your password: " << std::endl;
	std::cin >> newEmployee.password;
	std::cout << "Enter your id: " << std::endl;
	std::cin >> newEmployee.id;

	employees.push_back(newEmployee);
	std::cout << "Success! Employee has been created" << std::endl;

}

void dltEmp(std::vector <Employee>& employees){
	int id; 
	std::cout << "Enter id of employee" << std::endl;
	std::cin >> id;

	for (auto identify = employees.begin(); identify != employees.end(); identify++){
		if ((*identify).id == id) {
			employees.erase(identify);
			std::cout << "Success! Employee has been deleted" << std::endl;
		}
		else
			std::cout << "There is ni Emplyee with this id" << std::endl;
}


void UpdEmp(std::vector <Employee>&employees);{
	int id;
	std::cout << "Enter id of employee" << std::endl;
	std::cin >> id;
	std::string password; 

	for (auto identify = employees.begin(); identify != employees.end(); identify++) {
		if ((*identify).id == id) {
			std::cout << "Enter new password" << std::endl;
			std::cin >> password;
			(*identify).password = password;

		}
		else
			std::cout << "There is no Emplyee with this id" << std::endl;

	}

}

void demoEmp(const std::vector<Employee>&employees); {
	std::cout << "All employees" << std::endl;
	for (const auto& employee : employees) {
		std::cout << "Name" << employee.name << std::endl;
		std::cout << "Password" << employee.password << std::endl;
		std::cout << "id" << employee.id << std::endl;

	}

}




int main();{
	srand(time(NULL));

	/*Task 1*/

	/*
	unsigned rows, columns;
	std::cout << "Enter count of rows" << std::endl;
	std::cin >> rows;
	std::cout << "Enter count of columns" << std::endl;
	std::cin >> columns;

	int** array{ new int* [rows] {} };

	array = memory(array, rows, columns);
	array = randfill(array, rows, columns);

	std::cout << "Result for Task 1: " << std::endl;

	std::cout << "The length of main diagonal is: " << main_diag(array, rows, columns) << std::endl;

	demonstrate(array, rows, columns);

	dlt(array, rows);

	*/

	/*Task 2*/

	std::vector <Employee> employees;

	int flag;
	int ch;

	while (flag)
	{
		std::cout << "1: add employee" << std::endl;
		std::cout << "2: delete employee" << std::endl;
		std::cout << "3: update employee" << std::endl;
		std::cout << "4: all employees" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> ch;
		if (ch == 1 || ch == 2 || ch == 3 || ch == 4) {
			if (ch == 1)
				addEmp(employees);

			else if (ch == 2)
				dltEmp(employees);

			else if (ch == 3)
				UpdEmp(employees);

			else
				demoEmp(employees);

		}
		else
			std::cout << "Enter number from 1 to 4" << std::endl;

	}
	
}
