//843. n-皇后问题
#include<bits/stdc++.h>

using namespace std;

const int N = 20;

char a[N][N];
int n;
bool col[N], dg[N], udg[N];

void dfs(int u){
	if(u == n){
		for(int i = 0; i < n; i ++){
			
			for(int j = 0; j < n; j ++){
				cout << a[i][j];
			}
			
			cout << endl;
		}
		cout << endl;
		return;
	}
	for(int i = 0; i < n; i ++){
		if(!col[i] && !dg[u + i] && !udg[n + u - i]){
			a[u][i] = 'Q';
			col[i] = dg[u + i] = udg[n + u - i] = true;
			dfs(u + 1);
			col[i] = dg[u + i] = udg[n + u - i] = false;
			a[u][i] = '.';
		}
	}
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		for(int j = 0 ; j< n; j ++){
			a[i][j] = '.';
		}
	}
	dfs(0);
	return 0;
}
