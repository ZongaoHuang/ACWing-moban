//876. 快速幂求逆元
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int pmi(int a, int k, int p){
	int res = 1;
	while(k){
		if(k & 1)   res = (LL)res * a % p;
		a =(LL) a * a % p;
		k >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	while(n --){
		int a, p;
		cin >> a >> p;
		if(a % p){
			int res = pmi(a, p - 2, p);
			cout << res << endl;
		}
		else cout << "impossible" << endl;
	}
	return 0;
}
