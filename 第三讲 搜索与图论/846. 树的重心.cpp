//846. 树的重心
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = N * 2;
int h[N], e[M], ne[M], idx;
int n;
bool flag[N];
int ans = N;

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

int dfs(int u){
	flag[u] = true;
	int sum = 1, res = 0;
	for(int i = h[u]; i != -1; i = ne[i]){
		int j = e[i];
		if(!flag[j]){
			int s = dfs(j);
			res = max(res, s);
			sum += s;
		}
	}
	res = max(res, n - sum);
	ans = min(res, ans);
	return sum;
}

int main(){
	cin >> n;
	memset(h, -1, sizeof h);
	for(int i = 0; i < n - 1; i ++){
		int a, b;
		cin >> a >> b;
		add(a, b), add(b, a);
	}
	dfs(1);
	cout << ans << endl;
	return 0;
}
