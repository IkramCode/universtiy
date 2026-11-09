#include <stdio.h>

int main(){
    int marks;
    printf("Enter the marks between 0 and 100: ");
    scanf("%d", &marks);

    if(marks < 0 || marks > 100){
        fprintf(stderr, "Error : invalid marks\n");
        return 1;
    }

    char grade;
    if (marks >= 80)      grade = 'A';
    else if (marks >= 70) grade = 'B';
    else if (marks >= 60) grade = 'C';
    else if (marks >= 50) grade = 'D';
    else                  grade = 'F';

    printf("Grade: %c\n", grade);
    return 0;
}
