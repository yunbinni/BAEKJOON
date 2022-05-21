#include<bits/stdc++.h>
#define MAX 10000
using namespace std;

int unf[MAX+1];

struct Edge {
	int s;
	int e;
	int val;
	Edge(int a, int b, int c) {
		s=a;
		e=b;
		val=c;
	}
	bool operator<(const Edge &edge)const{
		return val<edge.val;
	}
};

int Find(int v) {
	if(v==unf[v]) return v;
	return unf[v]=Find(unf[v]);
}

void Union(int a, int b) {
	a=Find(a);
	b=Find(b);
	if(a!=b) unf[a]=b;
}

int main() {
	vector<Edge> Edges;
	int v, e, a, b, c, ret=0;
	scanf("%d %d", &v, &e);
	for(int i=1; i<=v; i++) unf[i]=i;
	for(int i=1; i<=e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		Edges.push_back(Edge(a, b, c));
	}
	sort(Edges.begin(), Edges.end());
	for(int i=0; i<e; i++) {
		int fa=Find(Edges[i].s);
		int fb=Find(Edges[i].e);
		if(fa!=fb) {
			ret+=Edges[i].val;
			Union(Edges[i].s, Edges[i].e);
		}
	}
	
	printf("%d\n", ret);
	
	return 0;
}
