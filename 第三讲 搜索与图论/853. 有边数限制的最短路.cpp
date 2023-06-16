//853. 有边数限制的最短路
#include<bits/stdc++.h>

using namespace std;

const int N = 510, M = 10010;

struct edge{
	int a, b, w;
}edges[M];

int dis[N], backup[N];
int n, m, k;

void bollman(){
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	for(int i = 0; i < k; i ++){
		memcpy(backup, dis, sizeof dis);
		for(int j = 0; j < m; j ++){
			int a = edges[j].a, b = edges[j].b, w = edges[j].w;
			dis[b] = min(dis[b], backup[a] + w);
		}
	}
	if(dis[n] > 0x3f3f3f3f / 2) cout << "impossible" << endl;
	else cout << dis[n];
}

int main(){
	cin >> n >> m >> k;
	for(int i = 0; i < m; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		edges[i] = {x, y, z};
	}
	bollman();
	return 0;
}
