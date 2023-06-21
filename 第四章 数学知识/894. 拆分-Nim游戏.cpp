//894. 拆分-Nim游戏
#include<bits/stdc++.h>
using namespace std;

const int N = 110;

int f[N], n;

int sg(int x){
	if(f[x] != -1)  return f[x];
	unordered_set <int> S;
	for(int i = 0; i < x; i ++){
		for(int j = 0; j <= i; j ++){
			S.insert(sg(i) ^ sg(j));
		}
	}
	for(int i = 0;; i ++){
		if(!S.count(i))    return f[x] = i;
	}
}

int main(){
	cin >> n;
	memset(f, -1, sizeof f);
	int res = 0;
	for(int i = 0; i < n ; i ++){
		int x;
		cin >> x;
		res ^= sg(x);
	}
	if(res) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
