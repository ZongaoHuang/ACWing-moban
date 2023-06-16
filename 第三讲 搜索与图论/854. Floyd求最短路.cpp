//854. Floyd求最短路
#include<bits/stdc++.h>

using namespace std;

const int N = 210, INF = 1e9;
int g[N][N];
int n, m, k;

void fylod(){
	for(int k = 1; k <= n; k ++){
		for(int i = 1; i <= n; i ++){
			for(int j = 1; j <= n; j ++){
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
}

int main(){
	cin >> n >> m >> k;
	for(int i = 1; i<= n; i ++){
		for(int j = 1; j <= n; j ++){
			if(i == j) g[i][j] = 0;
			else g[i][j] = INF;
		}
	}
	for(int i = 0; i < m; i ++){
		int a, b, c;
		cin >> a >> b >> c;
		g[a][b] = min(g[a][b], c);
	}
	fylod();
	while(k --){
		int x, y;
		cin >> x >> y;
		if(g[x][y] > 0x3f3f3f3f / 2)   cout << "impossible" << endl;
		else cout << g[x][y] << endl;
	}
	return 0;
}
