#include <stdio.h>
#include <stdbool.h>

bool checkPalindromeNumber(int number){
    int original = number;
    int reversed = 0;
    while (number > 0){
       reversed = reversed * 10 + number % 10;
       number /= 10;
    }

    return original == reversed;
}

int main(){

     int num;

    printf("Enter an integer: ");
    scanf("%d", &num);

    if (checkPalindromeNumber(num)) {
        printf("%d is a palindrome.\n", num);
    } else {
        printf("%d is not a palindrome.\n", num);
    }

    return 0;
}
