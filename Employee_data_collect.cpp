#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

// Employee structure
struct Employee {
    int employeeID;
    char name[50];
    char designation[50];
    double salary;
};

// Function to add employee information
void addEmployee() {
    ofstream file("employee_data.dat", ios::binary | ios::app);
    
    Employee employee;
    
    cout << "Enter employee ID: ";
    cin >> employee.employeeID;
    
    cout << "Enter employee name: ";
    cin.ignore();
    cin.getline(employee.name, 50);
    
    cout << "Enter employee designation: ";
    cin.getline(employee.designation, 50);
    
    cout << "Enter employee salary: ";
    cin >> employee.salary;
    
    file.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
    
    file.close();
    
    cout << "Employee added successfully." << endl;
}

// Function to delete employee information
void deleteEmployee() {
    ifstream file("employee_data.dat", ios::binary);
    ofstream tempFile("temp.dat", ios::binary);
    
    int employeeID;
    bool found = false;
    
    cout << "Enter employee ID to delete: ";
    cin >> employeeID;
    
    Employee employee;
    
    while (file.read(reinterpret_cast<char*>(&employee), sizeof(Employee))) {
        if (employee.employeeID == employeeID) {
            found = true;
            cout << "Employee with ID " << employeeID << " deleted successfully." << endl;
            continue;
        }
        
        tempFile.write(reinterpret_cast<char*>(&employee), sizeof(Employee));
    }
    
    file.close();
    tempFile.close();
    
    remove("employee_data.dat");
    rename("temp.dat", "employee_data.dat");
    
    if (!found)
        cout << "Employee with ID " << employeeID << " not found." << endl;
}

int main() {
    int choice;
    
    do {
        cout << "1. Add employee\n";
        cout << "2. Delete employee\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addEmployee();
                break;
                
            case 2:
                deleteEmployee();
                break;
                
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                break;
                
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);
    
    return 0;
}