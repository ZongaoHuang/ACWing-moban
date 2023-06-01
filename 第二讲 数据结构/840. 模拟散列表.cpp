//840. 模拟散列表
#include<bits/stdc++.h>

using namespace std;

const int N = 2e5 + 3, M = 0x3f3f3f3f;

int n;
int h[N];

int find(int x){
	int k = (x % N + N) % N;
	while(h[k] != M  && h[k] != x){
		k ++;
		if(k == N)  k = 0;
	}
	return k;
}


int main(){
	cin >> n;
	memset(h, 0x3f, sizeof h);
	while(n --){
		char c;
		int x;
		cin >> c >> x;
		int k = find(x);
		if(c == 'I'){
			h[k] = x;
		}
		else{
			if(h[k] != M)   cout << "Yes" << endl;
			else cout << "No" << endl;
		}
	}
	return 0;
}
