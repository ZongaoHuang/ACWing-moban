//868. 筛质数
#include<bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10;
int cnt, n, prime[N];
bool st[N];
int divide(int n){
	for(int i = 2; i <= n; i ++){
		if(!st[i])  prime[cnt ++ ] = i;
		for(int j = 0; prime[j] <= n / i; j ++){
			st[prime[j] * i] = true;
			if(i % prime[j] == 0)   break;
		}
	}
}

int main(){
	cin >> n;
	divide(n);
	cout << cnt << endl;
	return 0;
}
