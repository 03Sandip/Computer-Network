#include<stdio.h>
#include<string.h>

void main() {
    int big = 0;
    int i, c[10] = {0}, n, pos;

    
    printf("Enter the number of coefficients less than 10: ");
    scanf("%d", &n);
    printf("Enter the coefficients of x:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &pos);
        if(big < pos) {
            big = pos;  
        }
        if (pos < 10) {
            c[pos] = 1; 
        } else {
            printf("Coefficient position exceeds the array size (max 9). Please enter valid positions.\n");
            return;
        }
    }

    printf("\nThe Divisor in Binary is: ");
    for(i = big; i >= 0; i--) {
        printf("%d", c[i]);
    }

    printf("\n");
}
