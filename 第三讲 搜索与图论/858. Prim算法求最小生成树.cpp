//858. Prim算法求最小生成树
#include<bits/stdc++.h>

using namespace std;
const int N = 510, M = 1e5 + 10, INF = 0x3f3f3f3f;
int g[N][N], n, m, dis[N];
bool st[N];
int prim(){
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	int res = 0;
	for(int i = 0; i < n; i ++){
		int t = -1;
		for(int j = 1; j <= n; j ++){
			if(!st[j] && (t == -1 || dis[t] > dis[j])){
				t = j;
			}
		}
		if(i && dis[t] == INF)  return INF;
		if(i)   res += dis[t];
		for(int j = 1; j <= n; j ++){
			dis[j] = min(dis[j], g[t][j]);
		}
		st[t] = true;
	}
	return res;
}

int main(){
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for(int i = 0; i < m; i ++){
		int u, v, w;
		cin >> u >> v >> w;
		g[u][v] = g[v][u] = min(g[u][v], w);
	}
	int t = prim();
	if(t == INF)    cout << "impossible" << endl;
	else cout << t << endl;
	return 0;
}
