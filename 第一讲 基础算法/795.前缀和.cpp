//795.前缀和
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N],s[N];

int main(){
	cin >> n >> m;
	s[0] = 0;
	for(int i = 1;  i <= n; i ++){
		cin >> a[i];
		s[i] += s[i - 1] + a[i];
	}
	while(m --){
		int l, r;
		cin >> l >> r;
		cout << s[r] - s[l - 1] << endl;
	}
	return 0;
}
