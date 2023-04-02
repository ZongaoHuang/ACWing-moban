//790.数的三次方根
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

double n;

int main(){
	cin >> n;
	double l = -10000, r = 10000;
	while(r - l > 1e-8){
		double mid = (l + r) /2 ;
		if(mid * mid * mid < n) l = mid;
		else r = mid;
	}
	printf("%.6f", l);
	return 0;
}
