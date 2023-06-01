//240. 食物链
#include<iostream>

using namespace std;
const int N = 1e5 + 10;
int n, k, p[N], d[N];

int find(int x){
	if(p[x] != x){
		int t = find(p[x]);
		d[x] += d[p[x]];
		p[x] = t;
	}
	return p[x];
}
int main(){
	cin >> n >> k;
	int ans = 0;
	for(int i = 1; i <= n; i ++)    p[i] = i;
	while(k --){
		int t, x, y;
		cin >> t >> x >> y;
		if(x > n || y > n)  ans ++;
		
		else{
			int pa = find(x), pb = find(y);
			if(t == 1){
				
				if(pa == pb && (d[x] - d[y]) % 3)   ans ++;
				else if(pa != pb){
					p[pa] = pb;
					d[pa] = d[y] - d[x];
				}
			}
			else{
				
				if(pa == pb && (d[x] - d[y] - 1) % 3)   ans ++;
				else if(pa != pb){
					p[pa] = pb;
					d[pa] = d[y] + 1 - d[x];
				}
			}
		}
	}
	cout << ans << endl;
	return 0;
}
