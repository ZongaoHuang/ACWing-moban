//850. Dijkstra求最短路 II
#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

const int N = 2e5;
typedef pair<int, int> PII;

int e[N], h[N], ne[N], w[N], idx;
bool st[N];
int dis[N];
int n, m;

void add(int a, int b, int c){
	e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx ++;
}

int dis1(){
	memset(dis, 0x3f, sizeof dis);
	dis[1] = 0;
	priority_queue<PII, vector<PII>, greater<PII>> heap;
	heap.push({0, 1});
	while(heap.size()){
		auto t = heap.top();
		heap.pop();
		int ver = t.second, dis2 = t.first;
		if(st[ver]) continue;
		for(int i = h[ver]; i != -1; i = ne[i]){
			int j = e[i];
			if(dis[j] > dis2 + w[i]){
				dis[j] = dis2 + w[i];
				heap.push({dis[j], j});
			}
		}
	}
	if(dis[n] == 0x3f3f3f3f)    return -1;
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
	cout << dis1() << endl;
	return 0;
}
