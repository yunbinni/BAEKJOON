#include<cstdio>
#include<string>
using namespace std;

int a[]={0, 1,  2,   3,    4,     5,      6,       7,        8,        9};
int c[]={0, 9, 90, 900, 9000, 90000, 900000, 9000000, 90000000, 900000000};
int d[]={0, 1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000};

int main() {
	int n, res=0;
	scanf("%d", &n);
	string n_str=to_string(n);
	int dig=n_str.size();
	res+=(n-d[dig]+1)*dig;
	dig--;
	for(; dig>=0; dig--) {
		res+=c[dig]*a[dig];
	}
	printf("%d\n", res);
	return 0;
}
