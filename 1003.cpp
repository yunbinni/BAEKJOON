#include <iostream>
using namespace std;

int t, n;

long long arr[50] = {0,1,};
long long fibo(int N) {
    if(N == 0 || N == 1) return arr[N];
    if(arr[N] != 0) return arr[N];
    return arr[N] = fibo(N-1) + fibo(N-2);
}

int main() {
    cin >> t;
    while(t--)
    {
    	int temp;
        cin >> temp;
        if(temp == 0)
            cout << "1 0" << '\n';
        else
            cout << fibo(temp-1) << ' ' << fibo(temp) << '\n';
    }
    
    return 0;
}
