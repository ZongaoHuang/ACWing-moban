//861. 二分图的最大匹配
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 2e5 + 10;

int n1, n2, m, h[N], e[M], ne[M], idx, match[N];
bool st[N];

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool find(int u){
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!st[j]){
			st[j] = true;
			if(!match[j] || find(match[j])){
				match[j] = u;
				return true;
			}
		}
	}
	return false;
}

int main(){
	cin >> n1 >> n2 >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int u, v;
		cin >> u >> v;
		add(u, v);
	}
	int ans = 0;
	for(int i = 1; i <= n1; i ++){
		memset(st, false, sizeof st);
		if(find(i)) ans ++;
	}
	cout << ans << endl;
	return 0;
}
