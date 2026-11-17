#include <stdio.h>
#include <unistd.h>

int main () {
    char array[100];
    // int n = read(0, array, 100);
    //
    // printf("total bytes written:%d \n", n);

    size_t n = write(0, array, 100);
    printf("total bytes written:%d \n", n);
    
    // write(2, "error", 6);
}
