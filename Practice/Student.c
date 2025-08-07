#include <stdio.h>

typedef struct {
    char * name;
    int mark;
} student;

int main() {
    int i;
    student students[5];
    student topStudent;

    student zeroth = {"zero",5};
    student first = {"one",10};
    student second = {"two",3};
    student third = {"three",7};
    student fourth = {"four", 88};
    
    students[0] = zeroth;
    students[1] = first;
    students[2] = second;
    students[3] = third;
    students[4] = fourth;

    topStudent = zeroth;

    for(i = 1; i < 5; i++) {
        int highestMark = topStudent.mark;
        int thisMark = students[i].mark;
        if (thisMark > highestMark) {
            topStudent = students[i];
        }
    }

    printf("The top student is %s with a mark of %d\n", topStudent.name, topStudent.mark);
    return 0;
}
