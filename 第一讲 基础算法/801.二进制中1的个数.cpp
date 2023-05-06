//801.二进制中1的个数
#include<bits/stdc++.h>

using namespace std;

int n;

int lowbit(int t){
	return t & (-t);
}

int main(){
	cin >> n;
	while(n --){
		int res = 0;
		int t;
		cin >> t;
		while(t){
			t -= lowbit(t);
			res ++;
		}
		cout << res << " ";
	}
	return 0;
}
