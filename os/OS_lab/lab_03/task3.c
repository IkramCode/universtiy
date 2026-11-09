#include <stdio.h>

int main(){
    int input_numbers = 15;
    int integers[input_numbers];
    int input;
    int input_count = 0;

    printf("Enter 15 numbers, -1 at the end if u want lesser numbers: ");
    for(int i = 0; i < input_numbers ; i++){
       scanf("%d", &input);
       if (input == -1) {
           break;
       } else{
       integers[i] = input;
       input_count++;
         }       
    }

    printf("Input array \n");
    for (int i = 0; i < input_count; i++){
        printf("%d ", integers[i]);
    }
    printf("\n");

    // selection sort
    for (int i = 0; i < input_count; i++){

        int max_idx = i;
        for (int j = i + 1; j < input_count; j++){
           if(integers[j] > integers[max_idx]){
               max_idx = j;
           }
        }

        int temp = integers[max_idx];
        integers[max_idx] = integers[i];
        integers[i] = temp;
    }

    printf("selcted sort descending order \n");
    for (int i = 0; i < input_count; i++){
        printf("%d ", integers[i]);
    }
    return 0;
}
