//838. 堆排序
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int n, m, s, h[N];

void down(int x){
	int u = x;
	if(2 * x <= s &&h[2 * x] < h[u])    u = 2 * x;
	if(2 * x + 1 <= s && h[2 * x + 1] < h[u])   u = 2 * x + 1;
	if(u != x){
		swap(h[u], h[x]);
		down(u);
	}
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)    cin >> h[i];
	s = n;
	for(int i = n / 2; i; i --) down(i);
	while(m --){
		cout << h[1] << " ";
		h[1] = h[s];
		s --;
		down(1);
	}
	return 0;
}
