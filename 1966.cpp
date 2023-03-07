#include <bits/stdc++.h>
using namespace std;

struct Document {
	int number;
	int importance;
	
	Document(int pnumber, int pimportance) {
		number = pnumber;
		importance = pimportance;
	}
};

int T;
int N, M;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >> T;
	
	while(T--)
	{
		cin >> N >> M;
		
		queue<Document> Documents;
		
		priority_queue<int> Importances;
		
		int count = 0;
		
		for(int i = 0; i < N; i++) {
			int importance; cin >> importance;
			
			Documents.push(Document(i, importance));
			
			Importances.push(importance);
		}
		
		while(!Documents.empty())
		{
			int number = Documents.front().number;
			int importance = Documents.front().importance;
			
			if(Importances.top() > importance) {
				Documents.push(Documents.front());
				Documents.pop();
			}
			
			else {
				Documents.pop();
				Importances.pop();
				count++;
				
				if(number == M) {
					cout << count << "\n";
					break;
				}
			}
		}
	}
	
	return 0;
}
