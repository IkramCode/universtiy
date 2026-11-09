#include <stdio.h>

int main(int argc, char *argv[]){
    int a,b;

   if(argc != 3){
       fprintf(stderr, "Error: expected 2 arguments.\n");
   } 

   if (sscanf(argv[1], "%d", &a) != 1 || sscanf(argv[2], "%d", &b) != 1) {
        fprintf(stderr, "Error: arguments must be integers\n");
        return 1;
    }
    if (b == 0) {
        fprintf(stderr, "Error: second number must not be zero\n");
        return 1;
    }

    printf("Sum: %d\n", a + b);
    printf("Difference: %d\n", a - b);
    return 0;

}


