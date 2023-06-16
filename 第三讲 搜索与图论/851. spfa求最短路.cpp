//851. spfa求最短路
#include<bits/stdc++.h>

using namespace std;

typedef pair<int, int> PII;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx, dis[N], w[N];
bool st[N];
int n, m;
void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int spfa(){
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	queue<int> q;
	q.push(1);
	st[1] = true;
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dis[j] > dis[t] + w[i]){
				dis[j] = dis[t] + w[i];
				if(!st[j]){
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return dis[n];
}

int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	for(int i = 0; i < m; i ++){
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	if(spfa() == 0x3f3f3f3f)    cout << "impossible" << endl;
	else cout << spfa()  << endl;
	return 0;
}
