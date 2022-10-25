#include<bits/stdc++.h>
#define Voyager 1004
using namespace std;

const int maxN=504;

int intDirection[4][2] = { {-1,0}, {0,1}, {1,0}, {0,-1} };
char charDirection[4] = {'U', 'R', 'D', 'L'};
struct Signal {
	int direction;
	int movements;
	int row;
	int column;
	
	Signal() {}
	
	Signal(int pdirection, int pmovements, int prow, int pcolumn) {
		direction=pdirection;
		movements=pmovements;
		row=prow;
		column=pcolumn;
	}
};

int N, M;
char arr[maxN][maxN];
int PR, PC;

int visited[4][maxN][maxN];

void input() {
	cin>>N>>M;
	for(int i=1; i<=N; i++)
		for(int j=1; j<=M; j++)
			cin>>arr[i][j];
	cin>>PR>>PC;
}

bool isMovable(Signal signal) {
	if(signal.row>=1 && signal.row<=N && signal.column>=1 && signal.column<=M) {
		if(arr[signal.row][signal.column]=='C')
			return false;
		return true;
	}
	return false;
}

int move(Signal signal) {
	visited[signal.direction][signal.row][signal.column]=signal.movements;
	return signal.movements;
}

Signal makeNewSignal(Signal current) {
	Signal next;
	
	if(arr[current.row][current.column]=='/') {
		if(current.direction%2==0)
			next.direction=current.direction+1;
		else
			next.direction=current.direction-1;
	}
	else if(arr[current.row][current.column]=='\\')
		next.direction=3-current.direction;
	else
		next.direction=current.direction;
	
	next.movements=current.movements+1;
	
	next.row=current.row+intDirection[next.direction][0];
	next.column=current.column+intDirection[next.direction][1];
	
	return next;
}

void solve() {
	char res1='U';
	int res2=0;
	
	for(int i=0; i<4; i++) {
		memset(visited, 0, sizeof visited);
		Signal signal(i, 1, PR, PC);
		while(isMovable(signal)) {
			if(visited[signal.direction][signal.row][signal.column]>0) {
				cout<<charDirection[signal.direction]<<"\n"<<"Voyager\n";
				return;
			}
			
			int tmp=move(signal);
			
			if(tmp>res2) {
				res1=charDirection[i];
				res2=tmp;
			}
			
			signal=makeNewSignal(signal);
		}
	}
	
	cout<<res1<<"\n"<<res2<<"\n";
}

int main() {
	ios_base::sync_with_stdio(0);
	input();
	solve();
	return 0;
}
