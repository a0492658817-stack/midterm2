#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, m, arry[10][10], x, y, min, visited[10][10];

    memset(visited, 0, sizeof(visited));

    // input arry space
    scanf("%d %d", &n, &m);

    // input arry
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &arry[i][j]);
        }
    }

    // find minimal
    min = arry[0][0];
    x = 0;
    y = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arry[i][j] < min) {
                min = arry[i][j];
                x = i;
                y = j;
            }
        }
    }

    // オ
    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int ans = arry[x][y];
    visited[x][y] = 1;

    int step = 1;

    // ǐ隔絬
    while (1) {
        int found = 0;
        int nr = -1, nc = -1;

        for (int k = 0; k < 4; k++) {
            int tr = x + dr[k];
            int tc = y + dc[k];

            if (tr >= 0 && tr < n && tc >= 0 && tc < m && !visited[tr][tc]) {
                if (!found) {
                    nr = tr;
                    nc = tc;
                    found = 1;
                } else {
                    // 计˙т程
                    if (step % 2 == 1) {
                        if (arry[tr][tc] < arry[nr][nc]) {
                            nr = tr;
                            nc = tc;
                        }
                    }
                    // 案计˙т程
                    else {
                        if (arry[tr][tc] > arry[nr][nc]) {
                            nr = tr;
                            nc = tc;
                        }
                    }
                }
            }
        }

        // ⊿Τǐ翴碞挡
        if (!found) {
            break;
        }

        // ǐ翴
        x = nr;
        y = nc;
        visited[x][y] = 1;
        ans += arry[x][y];
        step++;
    }

    printf("%d\n", ans);

    return 0;
}
