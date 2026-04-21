#include <stdio.h>

int main() {
    int n, m;

    // 讀入 N 和 M
    if (scanf("%d", &n) != 1 || scanf("%d", &m) != 1) {
        printf("error");
        return 0;
    }

    // 範圍檢查
    if (n < 1 || n > 2 || m < 2 || m > 9) {
        printf("error");
        return 0;
    }
    if (n== 1) {
        for (int i = 1; i <= m; i++) {
            // 左邊井字號
            for (int j = 1; j <= m - i; j++) {
                printf("#");
            }

            char ch;
            if (i % 3 == 0) {
                ch = 'B';
            } else if (i % 3 == 1) {
                ch = 'C';
            } else {
                ch = 'A';
            }

            for (int j = 1; j <= i; j++) {
                printf("*");
                if (j != i) {
                    printf("%c", ch);
                }
            }

            // 右邊井字號
            for (int j = 1; j <= m - i; j++) {
                printf("#");
            }

            printf("\n");
        }
    }
    if(n==2){
        for (int i = 1; i <= m; i++) {

        // 左邊：i 到 1
            for (int j = i; j >= 1; j--) {
                printf("%d", j);
            }

        // 中間：星號
            for (int j = 1; j <= 2 * (m - i + 1); j++) {
                printf("*");
            }

        // 右邊：1 到 i
            for (int j = 1; j <= i; j++) {
                printf("%d", j);
            }

            printf("\n");
        }
    }
}
