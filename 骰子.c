#include <stdio.h>

void roll(int d[], char dir, int t) {
    t %= 4;
    while (t--) {
        int temp;
        if (dir == 'F') {
            temp = d[0];
            d[0] = d[5];
            d[5] = d[1];
            d[1] = d[4];
            d[4] = temp;
        }
        else if (dir == 'B') {
            temp = d[0];
            d[0] = d[4];
            d[4] = d[1];
            d[1] = d[5];
            d[5] = temp;
        }
        else if (dir == 'R') {
            temp = d[0];
            d[0] = d[2];
            d[2] = d[1];
            d[1] = d[3];
            d[3] = temp;
        }
        else if (dir == 'L') {
            temp = d[0];
            d[0] = d[3];
            d[3] = d[1];
            d[1] = d[2];
            d[2] = temp;
        }
    }
}

int score(int a, int b, int c) {
    if (a == b && b == c) return a * 2;
    if (a == b) return c;
    if (a == c) return b;
    if (b == c) return a;
    return 0;
}

int main() {
    int origin[3][6];
    int A[3][6], B[3][6];
    int N;

    // 只讀 3 顆骰子的初始資料
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            scanf("%d", &origin[i][j]);
        }
    }

    // 複製給 A 和 B
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 6; j++) {
            A[i][j] = origin[i][j];
            B[i][j] = origin[i][j];
        }
    }

    scanf("%d", &N);

    // A 的三顆骰子，各做 N 次操作
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            char dir;
            int t;
            scanf(" %c%d", &dir, &t);
            roll(A[i], dir, t);
        }
    }

    // B 的三顆骰子，各做 N 次操作
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < N; j++) {
            char dir;
            int t;
            scanf(" %c%d", &dir, &t);
            roll(B[i], dir, t);
        }
    }

    int SA = score(A[0][0], A[1][0], A[2][0]);
    int SB = score(B[0][0], B[1][0], B[2][0]);

    if (SA > SB) printf("A win\n");
    else if (SA < SB) printf("B win\n");
    else printf("Tie\n");

    printf("%d %d\n", SA, SB);

    return 0;
}
