#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    cin >> a >> b >> c;

    // ����� ���ݺ��� ũ�ų� ������ ���͹߻� �Ұ� 
    if(b >= c)
        cout << -1;
    else
        cout << (a / (c - b) + 1);
}
