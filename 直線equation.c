#include <stdio.h>
#include <stdlib.h>

// 最大公因數
long long gcd(long long a, long long b){
    if(b == 0) return llabs(a);
    return gcd(b, a % b);
}

// 約分（用指標）
void simplify(long long *num, long long *den){
    long long g = gcd(*num, *den);
    *num /= g;
    *den /= g;

    // 分母保持正
    if(*den < 0){
        *num = -*num;
        *den = -*den;
    }
}

// 印分數
void print_frac(long long num, long long den){
    if(den == 1) printf("%lld", num);
    else printf("%lld/%lld", num, den);
}

int main(){
    int N;
    scanf("%d", &N);

    while(N--){
        long long x1, y1, x2, y2;
        scanf("%lld %lld %lld %lld", &x1, &y1, &x2, &y2);

        // m = (y1 - y2) / (x1 - x2)
        long long m_num = y1 - y2;
        long long m_den = x1 - x2;

        // b = (x2*y1 - x1*y2) / (x2 - x1)
        long long b_num = x2 * y1 - x1 * y2;
        long long b_den = x2 - x1;

        // 約分（用指標）
        simplify(&m_num, &m_den);
        simplify(&b_num, &b_den);

        printf("y = ");

        // ===== 處理 m =====
        if(m_num == 0){
            // y = b
            print_frac(b_num, b_den);
        }
        else{
            // m = 1 or -1
            if(m_num == m_den) printf("x");
            else if(m_num == -m_den) printf("-x");
            else{
                print_frac(m_num, m_den);
                printf("x");
            }

            // ===== 處理 b =====
            if(b_num > 0){
                printf(" + ");
                print_frac(b_num, b_den);
            }
            else if(b_num < 0){
                printf(" - ");
                print_frac(llabs(b_num), b_den);
            }
        }

        printf("\n");
    }

    return 0;
}
