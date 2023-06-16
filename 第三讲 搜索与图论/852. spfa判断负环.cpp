//852. spfa判断负环
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 1e5 + 10;

typedef pair<int, int>PII;
int n,m,cnt[N],h[N],e[M],ne[M],w[N],idx,dis[N];
bool st[N];
void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

bool spfa(){
	queue<int> q;
	for(int i = 1; i <= n; i ++){
		st[i] = true;
		q.push(i);
	}
	while(!q.empty()){
		auto t = q.front();
		q.pop();
		st[t] = false;
		for(int i = h[t]; i != -1; i = ne[i]){
			int j = e[i];
			if(dis[j] > dis[t] + w[i]){
				cnt[j] = cnt[t] + 1;
				dis[j] = dis[t] + w[i];
				if(cnt[j] >= n) return true;
				if(!st[j]){
					q.push(j);
					st[j] = true;
				}
			}
		}
	}
	return false;
}
int main(){
	cin >> n >> m;
	memset(h, -1, sizeof h);
	while(m --){
		int x, y, z;
		cin >> x >> y >> z;
		add(x, y, z);
	}
	if(spfa()){
		cout << "Yes" << endl;
	}
	else cout << "No" << endl;
	return 0;
}
