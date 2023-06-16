//849. Dijkstra求最短路 I
#include<iostream>
#include<cstring>

using namespace std;

const int N = 510;

int g[N][N], dis[N], n, m;
bool st[N];

int dis1(){
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	
	for(int i = 0; i < n; i ++){
		int t = -1;
		for(int j = 1; j <= n; j ++){
			if(!st[j] && (t == -1 || dis[t] > dis[j])){
				t = j;
			}
		}
		st[t] = true;
		for(int j = 1; j <= n; j ++){
			dis[j] = min(dis[j], dis[t] + g[t][j]);
		}
	}
	if(dis[n] == 0x3f3f3f3f)    return -1;
	return dis[n];
}

int main(){
	cin >> n >> m;
	memset(g, 0x3f, sizeof g);
	for(int i = 0; i < m; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		g[x][y] = min(g[x][y], z);
	}
	cout << dis1() << endl;
	return 0;
}
