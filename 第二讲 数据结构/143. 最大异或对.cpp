//143. 最大异或对
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 3e7;

int n, son[M][2], idx, a[N];

void insert(int x){
	int p = 0;
	for(int i = 30; ~i; i --){
		int u = x >> i & 1;
		if(!son[p][u])  son[p][u] = ++idx;
		p = son[p][u];
	}
}

int query(int x){
	int p = 0, res = 0;
	for(int i = 30; ~i; i --){
		int u = x >> i & 1;
		if(son[p][!u]){
			res += 1 << i;
			p = son[p][!u];
		}
		else p = son[p][u];
	}
	return res;
}
int main(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
		insert(a[i]);
	}
	
	int res = 0;
	for(int i = 0; i < n; i ++){
		res = max(res, query(a[i]));
	}
	cout << res << endl;
	return 0;
}
