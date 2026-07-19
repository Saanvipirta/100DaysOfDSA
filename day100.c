/*Write a C program to manage employee records using file handling. The program should allow users to:

Add Employee
Display Employees
Search Employee by ID
Update Employee Salary
Exit*/
#include <stdio.h>
#include <stdlib.h>

struct Employee {
    int id;
    char name[50];
    float salary;
};

void addEmployee() {
    FILE *fp = fopen("employees.dat", "ab");
    struct Employee emp;

    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);

    printf("Enter Employee Name: ");
    scanf(" %[^\n]", emp.name);

    printf("Enter Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(emp), 1, fp);
    fclose(fp);

    printf("Employee added successfully!\n");
}

void displayEmployees() {
    FILE *fp = fopen("employees.dat", "rb");
    struct Employee emp;

    if (fp == NULL) {
        printf("No records found.\n");
        return;
    }

    printf("\nID\tName\t\tSalary\n");
    printf("---------------------------------\n");

    while (fread(&emp, sizeof(emp), 1, fp)) {
        printf("%d\t%s\t\t%.2f\n",
               emp.id, emp.name, emp.salary);
    }

    fclose(fp);
}

void searchEmployee() {
    FILE *fp = fopen("employees.dat", "rb");
    struct Employee emp;
    int id, found = 0;

    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp)) {
        if (emp.id == id) {
            printf("\nEmployee Found\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);
            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");

    fclose(fp);
}

void updateSalary() {
    FILE *fp = fopen("employees.dat", "rb+");
    struct Employee emp;
    int id, found = 0;
    float newSalary;

    printf("Enter Employee ID: ");
    scanf("%d", &id);

    while (fread(&emp, sizeof(emp), 1, fp)) {
        if (emp.id == id) {

            printf("Enter New Salary: ");
            scanf("%f", &newSalary);

            emp.salary = newSalary;

            fseek(fp, -sizeof(emp), SEEK_CUR);
            fwrite(&emp, sizeof(emp), 1, fp);

            printf("Salary updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Employee not found.\n");

    fclose(fp);
}

int main() {
    int choice;

    do {
        printf("\n===== Employee Management System =====\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees\n");
        printf("3. Search Employee\n");
        printf("4. Update Salary\n");
        printf("5. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                searchEmployee();
                break;
            case 4:
                updateSalary();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while (choice != 5);

    return 0;
}
