//799.最长连续不重复子序列
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n;
int a[N],b[N],res;

int main(){
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	
	res = 0;
	
	for(int i = 0, j = 0; i < n; i ++){
		b[a[i]] ++;
		while(b[a[i]] > 1){
			b[a[j]] --;
			j++;
		}
		res = max(res, i-j + 1);
	}
	cout << res << endl;
	return 0;
}
