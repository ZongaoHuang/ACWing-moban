//859. Kruskal算法求最小生成树
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;
int p[N], n, m;
struct edge{
	int a, b, w;
	bool operator < (const edge & W) const{
		return w < W.w;
	}
}edges[N];

int find(int x){
	if(p[x] != x)   p[x] = find(p[x]);
	return p[x];
}
int main(){
	cin >> n >> m;
	for(int i = 0; i < m; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		edges[i] = {a, b, c};
	}
	sort(edges, edges + m);
	int res = 0, cnt = 0;
	for(int i = 1; i <= n; i ++)    p[i] = i;
	for(int i = 0; i < m; i ++){
		int a = edges[i].a, b = edges[i].b, w = edges[i].w;
		a = find(a), b = find(b);
		if(a != b){
			p[a] = b;
			res += w;
			cnt ++;
		}
	}
	if(cnt > n - 1) cout << "impossible" << endl;
	else cout << res;
	return 0;
}
