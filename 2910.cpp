#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll INF = 1e18;

int n, c, a[1004];
vector<pair<int, int>> v;
map<int, int> mp, mp_first;

bool cmp(pair<int, int> a, pair<int, int> b) {
	if(a.second == b.second)
		return mp_first[a.first] < mp_first[b.first];
		
	return a.second > b.second;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	cin >> n >> c;
	for(int i = 0; i < n; i++) {
		cin >> a[i]; mp[a[i]]++;
		if(mp_first[a[i]] == 0) mp_first[a[i]] = i + 1;
	}
	
	for(auto it : mp) {
		v.push_back({it.first, it.second});
	}
	
	sort(v.begin(), v.end(), cmp);
	
	for(auto i : v) {
		for(int j = 0; j < i.second; j++) {
			cout << i.first << " ";
		}
	}
}
