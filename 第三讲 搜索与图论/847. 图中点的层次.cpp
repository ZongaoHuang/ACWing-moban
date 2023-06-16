//847. 图中点的层次
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx;
int d[N], q[N];
int n, m;

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
} 

int bfs(){
	int hh = 0, tt = 0;
	memset(d, -1, sizeof d);
	d[1] = 0, q[0] = 1;
	while(hh <= tt){
		auto t = q[hh ++];
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(d[j] == -1){
				q[++ tt] = j;
				d[j] = d[t] + 1;
			}
		}
	}
	return d[n];
}
int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b);
	}
	cout << bfs() << endl;
	return 0;
}
