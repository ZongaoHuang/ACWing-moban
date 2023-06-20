//875. 快速幂
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

int pmi(int a, int k, int p){
	int res = 1;
	while(k){
		if(k & 1)   res = (LL)res * a % p;
		a = (LL)a * a % p;
		k >>= 1;
	}
	return res;
}
int main(){
	int n;
	cin >> n;
	while(n --){
		int a, b, p;
		cin >> a >> b >> p;
		cout << pmi(a, b, p) << endl;
	}
	return 0;
}
