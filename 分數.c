#include <stdio.h>
#include <stdlib.h>

// 程そ计
long long gcd(long long a, long long b){
    if(b == 0) return llabs(a);
    return gcd(b, a % b);
}

// ﹃ △ 安だ计
int parse(char *s, long long *numerator, long long *denominator){
    long long integer = 0, num = 0, den = 0;
    int sign = 1;

    // 矪瞶璽腹
    if(s[0] == '-'){
        sign = -1;
        s++;
    }

    // 盿だ计 a(b/c)
    if(sscanf(s, "%lld(%lld/%lld)", &integer, &num, &den) == 3){
        if(den == 0) return 0;
        *numerator = sign * (integer * den + num);
        *denominator = den;
    }
    //だ计 b/c
    else if(sscanf(s, "%lld/%lld", &num, &den) == 2){
        if(den == 0) return 0;
        *numerator = sign * num;
        *denominator = den;
    }
    else{
        return 0;   // Α岿粇
    }

    return 1;
}

// 块挡狦锣盿だ计
void print_function(long long numerator, long long denominator){
    if(numerator == 0){
        printf("0\n");
        return;
    }

    int sign = 1;
    if(numerator < 0){
        sign = -1;
        numerator = -numerator;
    }

    // だ
    long long g = gcd(numerator, denominator);
    numerator /= g;
    denominator /= g;

    long long integer = numerator / denominator;
    long long remainder = numerator % denominator;

    if(sign == -1) printf("-");

    // 俱计
    if(remainder == 0){
        printf("%lld\n", integer);
    }
    // 1
    else if(integer == 0){
        printf("%lld/%lld\n", remainder, denominator);
    }
    // 盿だ计
    else{
        printf("%lld(%lld/%lld)\n", integer, remainder, denominator);
    }
}

int main(){
    char s1[100], s2[100];
    char op, COUNT;

    while(1){
        scanf("%s", s1);
        scanf(" %c", &op);
        scanf("%s", s2);

        long long numerator1, denominator1;
        long long numerator2, denominator2;

        // 秆猂岿粇
        if(!parse(s1, &numerator1, &denominator1) ||
           !parse(s2, &numerator2, &denominator2)){
            printf("error\n");
        }
        else{
            long long numerator = 0, denominator = 0;

            if(op == '+'){
                numerator = numerator1 * denominator2 + denominator1 * numerator2;
                denominator = denominator1 * denominator2;
            }
            else if(op == '-'){
                numerator = numerator1 * denominator2 - denominator1 * numerator2;
                denominator = denominator1 * denominator2;
            }
            else if(op == '*'){
                numerator = numerator1 * numerator2;
                denominator = denominator1 * denominator2;
            }
            else if(op == '/'){
                if(numerator2 == 0){
                    printf("error\n");
                    goto next;
                }
                numerator = numerator1 * denominator2;
                denominator = denominator1 * numerator2;
            }

            if(denominator == 0){
                printf("error\n");
            }
            else{
                print_function(numerator, denominator);
            }
        }

    next:
        scanf(" %c", &COUNT);
        if(COUNT == 'n') break;
    }

    return 0;
}
