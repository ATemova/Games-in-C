#include <stdio.h>

int main() {
    int n, sum = 0;

    printf("Enter how many numbers you want to sum: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        int num;
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        sum += num;
    }

    printf("The total sum is: %d\n", sum);

    return 0;
}
