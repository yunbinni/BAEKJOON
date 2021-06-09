#include <stdio.h>

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    // 비용이 가격보다 크거나 같으면 이익발생 불가 
    if(b >= c)
        printf("%d", -1);
    else
        printf("%d", (a / (c - b) + 1));
        
    return 0;
}
