//797.差分
#include<bits/stdc++.h>


using namespace std;

const int N = 1e5 + 10;
int n,m;
int a[N],b[N];

void insert(int l, int r, int c){
	b[l] += c;
	b[r + 1] -= c;
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)    cin >> a[i];
	for(int i = 1; i <= n; i ++)    insert(i, i, a[i]);
	while(m --){
		int l, r, c;
		cin >> l >> r >> c;
		insert(l, r, c);
	}
	for(int i = 1; i <= n; i ++){
		b[i] += b[i - 1];
		cout << b[i] << " ";
	}
	return 0;
}
