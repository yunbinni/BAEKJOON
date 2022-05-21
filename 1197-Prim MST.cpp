#include<bits/stdc++.h>
#define MAX 100000
using namespace std;

int chk[MAX+1];
vector<pair<int, int> > graph[10001];

struct Edge {
	int e;
	int val;
	Edge(int a, int b) {
		e=a;
		val=b;
	}
	bool operator<(const Edge &edge) const {
		return val>edge.val;
	}
};

int main() {
	int v, e, a, b, c, ret=0;
	priority_queue<Edge> pQ;
	scanf("%d %d", &v, &e);
	for(int i=1; i<=e; i++) {
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back(make_pair(b, c));
		graph[b].push_back(make_pair(a, c));
	}
	pQ.push(Edge(1, 0));
	while(!pQ.empty()) {
		Edge top=pQ.top(); pQ.pop();
		if(chk[top.e]==0) {
			chk[top.e]=1;
			ret+=top.val;
			for(pair<int, int> e : graph[top.e]) {
				pQ.push(Edge(e.first, e.second));
			}
		}
	}
	printf("%d\n", ret);
	return 0;
}
