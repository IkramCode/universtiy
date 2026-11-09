#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int *arr = malloc(n * sizeof(int));

    printf("Enter %d numbers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int largest = arr[0];
    int second = INT_MIN;
    int found = 0;   // becomes 1 once a second largest exists

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) {
            second = largest;
            largest = arr[i];
            found = 1;
        } else if (arr[i] < largest && (!found || arr[i] > second)) {
            second = arr[i];
            found = 1;
        }
    }

    if (!found) {
        printf("No second largest: all elements are equal.\n");
    } else {
        printf("Second largest: %d\n", second);
    }

    free(arr);
    arr = NULL;
    return 0;
}
