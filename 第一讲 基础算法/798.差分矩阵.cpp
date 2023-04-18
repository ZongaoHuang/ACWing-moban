//798.差分矩阵
#include<bits/stdc++.h>

using namespace std;

const int N = 1010;

int n, m, q;
int a[N][N], d[N][N];


void insert(int x1, int y1, int x2, int y2, int c){
	d[x1][y1] += c;
	d[x2+1][y1] -= c;
	d[x1][y2+1] -= c;
	d[x2+1][y2+1] += c;
}

int main(){
	
	cin >> n >> m >> q;
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			cin >> a[i][j];
			insert(i, j, i, j, a[i][j]);
		}
	}
	
	while(q --){
		int x1, y1, x2, y2, c;
		cin >> x1 >> y1 >> x2 >> y2 >> c;
		insert(x1, y1, x2, y2, c);
	}
	
	for(int i = 1; i <= n; i ++){
		for(int j = 1; j <= m; j ++){
			d[i][j] = d[i][j] + d[i-1][j] + d[i][j-1] - d[i-1][j-1];
			cout << d[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
