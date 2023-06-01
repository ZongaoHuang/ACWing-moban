//830. 单调栈
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, skt[N], tt;

int main(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		int x;
		cin >> x;
		while(skt[tt] >= x && tt)   tt --;
		if(tt)  cout << skt[tt] <<" ";
		else cout << "-1" << " ";
		skt[++ tt] = x;
	}
	return 0;
}
