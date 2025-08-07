#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char * name;
    int salary;
} employee;


employee * createEmployees() {
    employee * employees = (employee *)malloc(sizeof(employee) * 5);
    (*(employees + 0)).name = "zero";
    (*(employees + 0)).salary = 5000;
    (*(employees + 1)).name = "one";
    (*(employees + 1)).salary = 88000;
    return employees;
}

void displayEmployees (employee * employees) {
    int count = 0;
    printf("Employee Name        Salary");
    while ((employees + count) != NULL) {
        employee thisEmployee = (employee + count);
        printf("%s      %d", thisEmployee.name, thisEmployee.salary); 
    }
}

int main() {
    employee * employees;

    employees = createEmployees();
    displayEmployees(employees);

    free(employees);
    return 0;
}

