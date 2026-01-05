#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Student
{
    int roll;
    char *name;
    long int registration;
    char *branch;
    int semester;
    int admissionYear;
} Student;
Student *arr;
int count;
void init()
{
    count = 1;
    arr = (Student *)malloc(count * sizeof(Student));
}
void push(Student student)
{
    arr[count - 1].roll = student.roll;
    arr[count - 1].admissionYear = student.admissionYear;
    arr[count - 1].branch = student.branch;
    arr[count - 1].name = student.name;
    arr[count - 1].registration = student.registration;
    arr[count - 1].semester = student.semester;
    printf("Data pushed successfully .\n");

    count++;
    arr = (Student *)realloc(arr, (count * sizeof(Student)));
}
void pop(int roll)
{
    int idx = -1;
    for (int i = 0; i < count; i++)
    {
        if (arr[i].roll == roll)
        {
            idx = i;
        }
    }
    for (int i = idx; i < count; i++)
    {
        arr[i] = arr[i + 1];
    }

    count--;
    printf("Data poped successfully .\n");
}
void update()
{
}
void display()
{
    printf("-------------student info------------\n");
    for (int i = 0; i < count-1; i++)
    {
        printf("...............................\n\n");
        printf("Roll no : %d\n", arr[i].roll);
        printf("Registration no : %ld\n", arr[i].registration);
        printf("Admision year : %d\n", arr[i].admissionYear);
        printf("Student name : %s\n", arr[i].name);
        printf("Branch : %s\n", arr[i].branch);
        printf("Semester: %d\n", arr[i].semester);
        printf("...............................\n\n");

    }
}
int main()
{
    init();
    int n;
    printf("Number of students want to add: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        Student s;
        printf("Enter roll: ");
        scanf("%d",&s.roll);
        printf("Enter name: ");
        scanf("%s",&s.name);
        printf("Enter registration: ");
        scanf("%ld",&s.registration);
        printf("Enter branch: ");
        scanf("%s",&s.branch);
        printf("Enter semester: ");
        scanf("%d",&s.semester);
        printf("Enter admission year: ");
        scanf("%d",&s.admissionYear);
        push(s);

    }
    
    display();
    return 0;
}