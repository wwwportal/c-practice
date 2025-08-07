#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct {
	int id;
	char name[50];
	int salary;
} Employee;

typedef struct DLLNode DLLNode;
struct DLLNode{
	Employee data;
	DLLNode * prev;
	DLLNode * next;
};

void add(DLLNode ** list, Employee e) {
	DLLNode * head = *list;
	DLLNode * previous = (*list)->prev;
	while(head) {
		previous = head;
		head = head->next;
	}
	head = malloc(sizeof(DLLNode));
	head->data = e;
	head->prev = previous;
	head->next = NULL;
}

int main () {
	
	Employee a;
	Employee b;
	Employee c;
	DLLNode * head = malloc(sizeof(DLLNode));
	head->prev = NULL;
	head->next = NULL;

	a.id = 1;
	strcpy(a.name, "Sam");
	a.salary = 65000;

	b.id = 2;
	strcpy(b.name, "Max");
	b.salary = 55000;

	c.id = 3;
	strcpy(c.name, "Maria");
	c.salary = 77000;

	add(&head, a);
	add(&head, b);
	add(&head, c);
	
	return 0;
}
