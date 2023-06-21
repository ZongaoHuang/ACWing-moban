//892. 台阶-Nim游戏
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;
int main(){
	int n;
	cin >> n;
	int res = 0;
	for(int i = 1; i <= n; i ++){
		int x;
		cin >> x;
		if(i % 2)   res ^= x;
	}
	if(res)   cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
