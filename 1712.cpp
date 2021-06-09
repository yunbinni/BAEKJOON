#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // 비용이 가격보다 크거나 같으면 이익발생 불가 
    if(b >= c)
        cout << -1;
    else
        cout << (a / (c - b) + 1);
}
