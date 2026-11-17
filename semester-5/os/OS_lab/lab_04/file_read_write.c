#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main (){
    // FILE *fp = fopen("data.txt", "a");
    // if (fp == NULL){
    //     perror("fopen");
    //     return 1;
    // }
    // // fprintf(fp,"hello my name is %s , i am %d old\n", "ikram", 21);
    // fputs("this is a new line",fp);
    // fputc('A',fp);
    // fclose(fp);
    //
    FILE *fp = fopen("space.txt", "r");
    if (fp == NULL){
        fprintf(stderr , "file not found");
    }

    // fprintf(fp, "name,age,cgpa\n");
    // fprintf(fp, "%s,%d,%.2f\n", "Ikram", 21, 3.75);
    // int nums[] = {10,20,30,40,50};
    //
    // for (int i = 0; i < 5; i++){
    //     fprintf(fp, "%d ", nums[i]);
    // }
    // fprintf(fp, "\n");

    char line[256];
    fgets(line, sizeof(line), fp);
    
    while(fgets(line, sizeof(line), fp) != NULL){
        char* name = strtok(line, ",");
        int age = atoi(strtok(NULL, ","));
        float cgpa = atof(strtok(NULL, "\n"));
        printf("my name is %s , my age is %d , my cgpa is %.2f \n",name, age, cgpa);
    } 

    fclose(fp);
}










