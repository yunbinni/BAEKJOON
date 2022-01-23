#include <iostream>
using namespace std;

//안만난다 -> r2 + r1 < d, d < r2 - r1
//한점에서 -> r2 + r1 = d, d = r2 - r1
//두점에서 -> r2 + r1 > d, d > r2 - r1
//무수하게 -> r2 = r1, d = 0

int f(int x1, int y1, int r1, int x2, int y2, int r2) {
	int d_squared = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);	// squared distance, 제곱된 거리값
	
	if( r2*r2 + r1*r1 + 2*r2*r1 < d_squared || d_squared < r2*r2 + r1*r1 - 2*r2*r1 )
		return 0;
	
	else if ( r2*r2 + r1*r1 + 2*r2*r1 == d_squared || d_squared == r2*r2 + r1*r1 - 2*r2*r1 && d_squared != 0)
		return 1;
	
	else if ( r2*r2 + r1*r1 + 2*r2*r1 > d_squared && d_squared > r2*r2 + r1*r1 - 2*r2*r1 )
		return 2;
	
	else if ( r2 == r1 && d_squared == 0)
		return -1;
	 
	return 0;
}

int main(void) {
	int x1, y1, r1, x2, y2, r2, n;
	cin >> n;
	
	for(int i = 0; i < n; i++) {
		cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
		cout << f(x1, y1, r1, x2, y2, r2) << endl;
	}
	
	return 0;
}
