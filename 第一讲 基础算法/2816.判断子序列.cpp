//2816.判断子序列
#include<bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int n,m;
int a[N],b[N];
int main(){
	cin >> n >> m;
	for(int i = 1 ; i <= n; i ++)    cin >> a[i];
	for(int j = 1; j <= m; j ++)    cin >> b[j];
	int i = 1;
	for(int j = 1; j <= m; j ++){
		if(i <= n && a[i] == b[j]){
			i ++;
		}
	}
	if(i == n + 1)  cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;
}
