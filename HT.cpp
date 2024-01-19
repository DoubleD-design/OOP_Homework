#include <stdio.h>

void printBinary(int n) {
    unsigned int i;
    for (i = 1 << 31; i > 0; i = i / 2) {
        if(n & i) {
            printf("1");
        } else {
            printf("0");
        }
        if(i % 16 == 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {
   int N;
   scanf("%d", &N);
   printBinary(N);
   return 0;
}

