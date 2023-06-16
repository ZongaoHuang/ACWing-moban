//848. 有向图的拓扑序列
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int h[N], e[N], ne[N], idx;

int d[N], q[N];

int n, m;

void add(int a, int b){
	e[idx] = b, ne[idx] = h[a], h[a] = idx ++;
}

bool topsort(){
	int hh = 0, tt = -1;
	for(int i = 1; i <= n; i++){
		if(d[i] == 0){
			q[++ tt] = i;
		}
	}
	while(hh <= tt){
		auto t = q[hh ++];
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			d[j] --;
			if(d[j] == 0){
				q[++ tt] = j;
			}
		}
	}
	return tt == n - 1;
}
int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int a, b;
		cin >> a >> b;
		add(a, b);
		d[b] ++;
	}
	if(topsort()){
		for(int i = 0; i < n; i ++){
			cout << q[i] << " ";
		}
	}
	else cout << "-1" << endl;
	return 0;
}
