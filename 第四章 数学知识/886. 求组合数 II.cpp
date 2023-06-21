//886. 求组合数 II
#include<bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7, N = 1e5 + 10;

typedef long long LL;

long long fac[N], infac[N];

int quick_pow(int a, int k, int p){
	int res = 1;
	while(k){
		if(k & 1)   res = (LL)res * a % p;
		a = (LL)    a * a % p;
		k  >>= 1;
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	fac[0] = infac[0] = 1;
	for(int i = 1; i <= 1e5 ; i ++){
		fac[i] = fac[i - 1] * i % M;
		infac[i] = (LL)infac[i - 1] * quick_pow(i, M - 2, M) % M;
	}
	while(n --){
		int a, b;
		cin >> a >> b;
		cout << (LL)fac[a] * infac[a - b] % M * infac[b] % M << endl;
	}
	return 0;
}
