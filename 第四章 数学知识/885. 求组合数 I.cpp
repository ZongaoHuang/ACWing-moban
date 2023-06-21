//885. 求组合数 I
#include<bits/stdc++.h>
using namespace std;

const int N = 2010, M = 1e9 + 7;
int c[N][N];

void init(){
	for(int i = 0; i < N; i ++){
		for(int j = 0; j <= i; j ++){
			if(!j)  c[i][j] = 1;
			else{
				c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % M;
			}
		}
	}
}


int main(){
	int n;
	cin >> n;
	init();
	while(n --){
		int a, b;
		cin >> a >> b;
		cout << c[a][b] << endl;
	}
	return 0;
}
