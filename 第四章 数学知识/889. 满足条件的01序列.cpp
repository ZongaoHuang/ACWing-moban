//889. 满足条件的01序列
#include<bits/stdc++.h>

using namespace std;

const int N = 200010, M = 1e9 + 7;
typedef long long LL;
LL fac[N], infac[N];
LL quick(int a, int k, int m){
	LL ans = 1;
	while(k){
		if(k & 1)   ans = (LL) ans * a % m;
		a = (LL)a * a % m;
		k >>= 1;
	}
	return ans;
}

int main(){
	int n;
	cin >> n;
	fac[0] = infac[0] = 1;
	for(int i = 1; i <= N; i++){
		fac[i] = (LL)fac[i - 1] * i % M;
		infac[i] = (LL)infac[i - 1] * quick(i, M - 2, M) % M;
	}
	cout << (LL) fac[2 * n] * infac[n] % M *infac[n] % M * quick(n + 1, M - 2, M) % M << endl;
	return 0;
}
