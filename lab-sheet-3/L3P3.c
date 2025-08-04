#include<stdio.h>

typedef struct {
    char name[50];
    int roll_no;
    float marks;
} Student;

void read(Student* students, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter roll number of student: ");
        scanf("%d", &(students + i)->roll_no);
        printf("Enter name of student: ");
        scanf("%s", &(students + i)->name);
        getchar();
        printf("Enter marks of student: ");
        scanf("%f", &(students + i)->marks);
    }
}

void display(Student* students, int n) {
    int i;
    printf("Name\t\tRoll no.\t\Marks\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%f\n", (students+i)->name, (students+i)->roll_no, (students+i)->marks);
}

void highest(Student* students, int n) {
    Student high;
    high.marks = -1;
    int i;
    for(i = 0; i < n; i++) {
        if((students + i)->marks > high.marks) {
            high = *(students + i);
        }
    }
    Student highArr[] = {high};
    printf("Details of student with highest marks:\n");
    display(highArr, 1);
}

int main() {
    int n;
    printf("Enter number of students in school: ");
    scanf("%d", &n);

    Student students[n];

    read(students, n);
    display(students, n);
    highest(students, n);

    return 0;
}
