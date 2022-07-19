#include<bits/stdc++.h>
using namespace std;

int n, m;
int unf[1000004];

int Find(int v) {
	if(unf[v]==v) return v;
	return unf[v]=Find(unf[v]);
}

void Union(int a, int b) {
	 a=Find(a);
	 b=Find(b);
	 if(a!=b) unf[a]=b;
}

int main() {
	ios_base::sync_with_stdio(0);
	for(int i=1; i<=1000004; i++) unf[i]=i;
	cin>>n>>m;
	int a, b, c;
	while(m--) {
		cin>>a>>b>>c;
		if(a==0) Union(b, c);
		if(a==1) {
			int fb=Find(b);
			int fc=Find(c);
			if(fb==fc) puts("YES");
			if(fb!=fc) puts("NO");
		}
	}
	return 0;
}
