//842. 排列数字
#include<bits/stdc++.h>

using namespace std;

const int N = 10;
int n;
int path[N];
bool st[N];

void dfs(int u){
	if(u == n){
		for(int i = 0; i < n; i ++){
			cout << path[i] << " ";
		}
		cout << endl;
	}
	for(int i = 1; i <= n; i ++){
		if(!st[i]){
			st[i] = true;
			path[u] = i;
			dfs(u + 1);
			st[i] = false;		
		}
	}
}

int main(){
	n = 3;
	dfs(0);
	return 0;
}
