#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, m, res=0, zi; //zero index
	cin>>n>>m;
	vector<int> pos(n+1, 0);
	for(int i=0; i<n; i++) cin>>pos[i];
	sort(pos.begin(), pos.end());
	for(int i=0; i<=n; i++) if(pos[i]==0) {zi=i; break;}
	for(int i=0; i<zi; i+=m) res+=abs(pos[i]*2); //�������� 
	for(int i=n; i>zi; i-=m) res+=pos[i]*2;		 //�������
	res-=max(abs(pos[0]), abs(pos[n]));			 //�ִ�Ÿ��� ���������� �� ��ó�� ó��
	cout<<res;
	return 0;
}
