// 1)WAP in C using structure that takes input Name, DOB, RollNo and marks of 5 subjects from user and display the information: age, average marks and percentage.

 #include <stdio.h>
 struct Student {
     char name[50];
     char dob[11]; // Format: YYYY-MM-DD
     int rollNo;
     float marks[5];
 };
 struct Student getInfo(){
     struct Student s;
     printf("Enter Name: ");
     scanf("%s", s.name);
     printf("Enter Date of Birth (YYYY-MM-DD)in AD: ");
     scanf("%s", s.dob);
     printf("Enter Roll No: ");
     scanf("%d", &s.rollNo);
     printf("Enter marks for 5 subjects: ");
     for (int i = 0; i < 5; i++) {
         scanf("%f", &s.marks[i]);
     }
     return s;
 }
#include <time.h>

int calculateAge(char dob[]) {
    int year, month, day;
    sscanf(dob, "%d-%d-%d", &year, &month, &day);

    // Get current system date
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    int currentYear = tm.tm_year + 1900;
    int currentMonth = tm.tm_mon + 1;
    int currentDay = tm.tm_mday;

    int age = currentYear - year;
    if (currentMonth < month || (currentMonth == month && currentDay < day)) {
        age--;
    }
    return age;
}

float calculateAverage(float marks[], int size) {
    float sum = 0;
    for (int i = 0; i < size; i++) {
        sum += marks[i];
    }
    return sum / size;
}

float calculatePercentage(float marks[], int size) {
    float total = 0;
    for (int i = 0; i < size; i++) {
        total += marks[i];
    }
    return (total / (size * 100)) * 100;
}

void displayInfo(struct Student s) {
    printf("\nStudent Information:\n");
    printf("Name: %s\n", s.name);
    printf("Date of Birth: %s\n", s.dob);
    printf("Roll No: %d\n", s.rollNo);
    printf("Age: %d\n", calculateAge(s.dob));
    printf("Average Marks: %.2f\n", calculateAverage(s.marks, 5));
    printf("Percentage: %.2f%%\n", calculatePercentage(s.marks, 5));
}
 int main() {
     struct Student s = getInfo();
     displayInfo(s);
     return 0;
 }