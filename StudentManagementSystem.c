#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int studentCount = 0;

struct Student {
    char fullName[50];
    int roll;
    float cgpa;
    int courseID[5];
}st[200];

// Function prototypes for each task
void addStudent();
void findRoll();
void findName();
void findCourse();
void totalStudents();
void deleteStudent();
void updateStudent();

int main(){
    int choice, keepRunning = 1;
    while(keepRunning){
        printf("*************** Student Management System ***************\n\n");
        printf("What would you like to do?\n");
        printf("1. Add Student details\n");
        printf("2. View Student details based on their roll number\n");
        printf("3. View Student details based on their name\n");
        printf("4. View details of the students enrolled in a specific course ID\n");
        printf("5. Find the total number of students\n");
        printf("6. Delete Student details based on their roll number\n");
        printf("7. Update Student details based on their roll number\n");
        printf("8. Exit\n");
        printf("Enter your choice:");
        scanf("%d", &choice);
        printf("\n");
        switch(choice){
            case 1:
                addStudent();
                break;
            case 2:
                findRoll();
                break;
            case 3:
                findName();
                break;
            case 4:
                findCourse();
                break;
            case 5:
                totalStudents();
                break;
            case 6:
                deleteStudent();
                break;
            case 7:
                updateStudent();
                break;
            case 8:
                keepRunning = 0;
                break;
            default:
                printf("Invalid choice. Please try again.\n\n");
        }
    }
    return 0;
}

void addStudent(){
    studentCount++;
    printf("Enter the Student Details:\n");
    printf("Full Name: ");
    scanf(" %[^\n]", st[studentCount].fullName);
    printf("Roll Number: ");
    scanf("%d", &st[studentCount].roll);
    printf("CGPA: ");
    scanf("%f", &st[studentCount].cgpa);
    printf("Course IDs (Enter 5 course IDs):\n");
    for(int i = 0; i < 5; i++){
        scanf("%d", &st[studentCount].courseID[i]);
    }
    printf("Student added successfully \n\n");
}

void findRoll(){
    int x, found = 0;
    printf("Enter the roll number: ");
    scanf("%d", &x);
    for(int j = 1; j <= studentCount; j++){
        if(x == st[j].roll){
            printf("Student Details:\n");
            printf("Name: %s\n", st[j].fullName);
            printf("CGPA: %.2f\n", st[j].cgpa);
            printf("Course IDs: %d", st[j].courseID[0]);
            for(int i = 1; i < 5; i++){
                printf(", %d", st[j].courseID[i]);
            }
            printf("\n\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
    	printf("No students found with the roll number %d \n\n",x);
	}
}

void findName(){
    char name[50];
    int found = 0;
    printf("Enter the name: ");
    scanf(" %[^\n]", name);
    for(int j = 1; j <= studentCount; j++){
        if(strcmp(name, st[j].fullName) == 0){
            printf("Student Details:\n");
            printf("Roll Number: %d\n", st[j].roll);
            printf("CGPA: %.2f\n", st[j].cgpa);
            printf("Course IDs: %d", st[j].courseID[0]);
            for(int i = 1; i < 5; i++){
                printf(", %d", st[j].courseID[i]);
            }
            printf("\n\n");
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("No student found with name %s\n\n", name);
    }
}

void findCourse(){
    int id, found= 0;
    printf("Enter the course ID to find the details of students enrolled: ");
    scanf("%d", &id);
    printf("\n Students enrolled in course ID %d:\n", id);
    for(int j = 1; j <= studentCount; j++){
        for(int i = 0; i < 5; i++){
            if(id == st[j].courseID[i]){
                printf("Name: %s \n", st[j].fullName);
                printf("Roll Number: %d\n", st[j].roll);
                printf("CGPA: %.2f\n", st[j].cgpa);
                printf("\n\n");
                found = 1;
            }
        }
    }
    if(found == 0){
        printf("No student enrolled in course %d\n\n", id);
    }
}

void totalStudents(){
    printf("Total number of students: %d\n", studentCount);
    printf("The maximum number of students that can be added is 200.\n");
    printf("You can add %d more students.\n\n", 200 - studentCount);
}

void deleteStudent(){
    int x, found = 0;
    printf("Enter the roll number of the student to delete their details: ");
    scanf("%d", &x);
    printf("\n");
    for(int j = 1; j <= studentCount; j++){
        if(x == st[j].roll){
            for(int k = j; k < studentCount; k++){
                st[k] = st[k + 1];
            }
            studentCount--;
            printf("The details of the student with roll number %d has been deleted \n\n",x);
            found = 1;
            break;
        }
    }
    if(found == 0){
        printf("No student found with roll number %d\n\n", x);
    }
}

void updateStudent(){
    int x, found = 0;
    printf("Enter the roll number of the student to update their details: ");
    scanf("%d", &x);
    printf("\n");
    for(int j = 1; j <= studentCount; j++){
        if(x == st[j].roll){
            printf("Enter the new details:\n");
            printf("Full Name: ");
            scanf(" %[^\n]", st[j].fullName);
            printf("CGPA: ");
            scanf("%f", &st[j].cgpa);
            printf("Course IDs (Enter 5 course IDs): ");
            for(int i = 0; i < 5; i++){
                scanf("%d", &st[j].courseID[i]);
            }
            printf("\n\n");
            found =1;
            break;
        }
    }
    if(found == 0){
        printf("No student found with roll number %d\n\n", x);
    }
}