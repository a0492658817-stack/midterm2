#include <stdio.h>
#include <string.h>

char s[105];
int img[8][8];
int idx = 0;

/* 將 (x, y) 左上角、邊長 size 的區塊全部塗黑 */
void fill_black(int x, int y, int size) {
    for (int i = x; i < x + size; i++) {
        for (int j = y; j < y + size; j++) {
            img[i][j] = 1;
        }
    }
}

/* 遞迴解析 DF-expression */
void build(int x, int y, int size) {
    char c = s[idx++];

    if (c == '0') {
        // 全白，不用做事
        return;
    }
    else if (c == '1') {
        // 全黑，整塊塗黑
        fill_black(x, y, size);
        return;
    }
    else if (c == '2') {
        int half = size / 2;
        // 依序：左上、右上、左下、右下
        build(x, y, half);                 // 左上
        build(x, y + half, half);          // 右上
        build(x + half, y, half);          // 左下
        build(x + half, y + half, half);   // 右下
    }
}

int main() {
    int n;
    scanf("%s", s);
    scanf("%d", &n);

    memset(img, 0, sizeof(img));
    idx = 0;

    build(0, 0, n);

    int hasBlack = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (img[i][j] == 1) {
                printf("%d,%d\n", i, j);
                hasBlack = 1;
            }
        }
    }

    if (!hasBlack) {
        printf("all white\n");
    }

    return 0;
}
