#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Struct Definitions

typedef struct {
    int id;
    char name[50];
    int marks;
    int age;
    float salary;
} Person;

typedef struct DLLNode {
    Person data;
    struct DLLNode *prev;
    struct DLLNode *next;
} DLLNode;

// Functions Implementations

// Question 1: Highest marks student
Person findTopStudent(Person students[], int count) {
    Person top = students[0];
    for (int i = 1; i < count; i++)
        if (students[i].marks > top.marks)
            top = students[i];
    return top;
}

// Question 2: Update salary
void updateSalary(Person *person, float newSalary) {
    person->salary = newSalary;
}

// Question 3: Dynamically allocate employees, find highest salary
Person highestPaidPerson(Person *people, int n) {
    Person top = people[0];
    for (int i = 1; i < n; i++)
        if (people[i].salary > top.salary)
            top = people[i];
    return top;
}

// Question 4: Swap persons
void swapPersons(Person *p1, Person *p2) {
    Person temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

// Question 5: Write & read Person data
void writePeopleToFile(Person people[], int count, const char *filename) {
    FILE *f = fopen(filename, "wb");
    fwrite(people, sizeof(Person), count, f);
    fclose(f);
}

void readPeopleFromFile(const char *filename) {
    FILE *f = fopen(filename, "rb");
    Person p;
    while (fread(&p, sizeof(Person), 1, f) == 1)
        printf("Person ID: %d, Name: %s, Salary: %.2f, Age: %d, Marks: %d\n", p.id, p.name, p.salary, p.age, p.marks);
    fclose(f);
}

// Question 6: Increment person's age
void incrementAge(Person *p) {
    p->age += 1;
}

// Question 7: Segregate multiples of 3
int* segregateNumbers(const char *filename, int *size, int multiplesOf3) {
    FILE *f = fopen(filename, "r");
    int num, count = 0, cap = 10;
    int *arr = malloc(cap * sizeof(int));

    while (fscanf(f, "%d", &num) == 1) {
        if ((num % 3 == 0) == multiplesOf3) {
            if (count == cap) {
                cap *= 2;
                arr = realloc(arr, cap * sizeof(int));
            }
            arr[count++] = num;
        }
    }
    fclose(f);
    *size = count;
    return arr;
}

// Question 8: Doubly linked list - find highest salary
DLLNode* highestSalaryNode(DLLNode *head) {
    DLLNode *top = head;
    for (DLLNode *cur = head; cur != NULL; cur = cur->next)
        if (cur->data.salary > top->data.salary)
            top = cur;
    return top;
}

// Question 9: Count and sum nodes in Doubly linked list
int countNodes(DLLNode *head) {
    int count = 0;
    while (head) {
        count++;
        head = head->next;
    }
    return count;
}

float sumNodes(DLLNode *head) {
    float sum = 0;
    while (head) {
        sum += head->data.salary;
        head = head->next;
    }
    return sum;
}

void freeDoublyLinkedList(DLLNode *head) {
    DLLNode *current = head;
    DLLNode *nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }
}

int main() {
    // Test Question 1: Highest marks student
    Person students[3] = {{1, "Alice", 90, 20, 0.0}, {2, "Bob", 85, 22, 0.0}, {3, "Charlie", 95, 21, 0.0}};
    Person topStudent = findTopStudent(students, 3);
    printf("Top Student: %s with marks %d\n", topStudent.name, topStudent.marks);

    // Test Question 2: Update salary
    Person employee = {4, "David", 0, 30, 50000.0};
    updateSalary(&employee, 60000.0);
    printf("Updated Salary of %s: %.2f\n", employee.name, employee.salary);

    // Test Question 3: Dynamically allocate employees, find highest salary
    int empCount = 3;
    Person *employees = malloc(empCount * sizeof(Person));
    employees[0] = (Person){5, "Eve", 0, 28, 70000.0};
    employees[1] = (Person){6, "Frank", 0, 32, 80000.0};
    employees[2] = (Person){7, "Grace", 0, 29, 75000.0};

    Person highestPaid = highestPaidPerson(employees, empCount);
    printf("Highest Paid Person: %s with salary %.2f\n", highestPaid.name, highestPaid.salary);
    free(employees);

    // Test Question 4: Swap persons
    Person p1 = {8, "Hank", 0, 40, 45000.0};
    Person p2 = {9, "Ivy", 0, 35, 55000.0};
    swapPersons(&p1, &p2);
    printf("After swap: p1=%s, p2=%s\n", p1.name, p2.name);

    // Test Question 5: Write & read Person data
    const char *file = "people.dat";
    writePeopleToFile(students, 3, file);
    readPeopleFromFile(file);

    // Test Question 6: Increment person's age
    incrementAge(&employee);
    printf("Incremented age of %s: %d\n", employee.name, employee.age);

    // Test Question 8 & 9: Doubly linked list operations
    DLLNode *head = malloc(sizeof(DLLNode));
    head->data = (Person){10, "Jack", 0, 45, 90000.0};
    head->next = malloc(sizeof(DLLNode));
    head->next->data = (Person){11, "Kate", 0, 38, 95000.0};
    head->next->prev = head;
    head->next->next = NULL;

    DLLNode *topSalaryNode = highestSalaryNode(head);
    printf("Highest Salary in list: %s with salary %.2f\n", topSalaryNode->data.name, topSalaryNode->data.salary);

    printf("Node Count: %d\n", countNodes(head));
    printf("Sum of Salaries: %.2f\n", sumNodes(head));

    freeDoublyLinkedList(head);

    return 0;
}

