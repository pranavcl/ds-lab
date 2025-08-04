#include<stdio.h>

typedef struct {
    char name[50];
    int roll_no;
    char grade;
} Student;

void read(Student* students, int n) {
    int i;
    for(i = 0; i < n; i++) {
        printf("Enter roll number of student: ");
        scanf("%d", &students[i].roll_no);
        printf("Enter name of student: ");
        scanf("%s", students[i].name);
        getchar();
        printf("Enter grade of student: ");
        scanf("%c", &students[i].grade);
    }
}

void sort(Student* students, int n) {
    int i, j;
    for(i = 0; i < n - 1; i++) {
        for(j = 0; j < n - i - 1; j++) {
            if(students[j].roll_no > students[j+1].roll_no) {
                Student temp = students[j];
                students[j] = students[j+1];
                students[j+1] = temp;
            }
        }
    }
}

void display(Student* students, int n) {
    int i;
    printf("Name\t\tRoll no.\t\tGrade\n");
    for(i = 0; i < n; i++)
        printf("%s\t\t%d\t\t%c\n", students[i].name, students[i].roll_no, students[i].grade);
}

int main() {
    int n;
    printf("Enter number of students in school: ");
    scanf("%d", &n);

    Student students[n];

    read(students, n);
    sort(students, n);
    display(students, n);

    return 0;
}
