//AcWing 788.逆序对的数量
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

typedef long long LL;
int n, a[N];

LL merge(int a[], int l, int r){
	if(l >= r)  return 0;
	int mid = l + r >> 1;
	LL ans = merge(a, l, mid) + merge(a, mid + 1, r);
	int i = l, j = mid + 1, tmp[r - l + 1], k = 0;
	while(i <= mid && j <= r){
		if(a[i] <= a[j]) tmp[k ++] = a[i ++];
		else{
			ans += mid - i + 1;
			tmp[k ++] = a[j ++];
		}
	}
	while(i <= mid) tmp[k ++] = a[i ++];
	while(j <= r)   tmp[k ++] = a[j ++];
	for(int i = 0, j = l; j <= r; j ++,i ++)   a[j] = tmp[i];
	return ans;
}


int main(){
	cin >> n;
	for(int i = 0; i < n; i ++) cin >> a[i];
	LL ans = merge(a, 0, n - 1);
	cout << ans << endl;
	return 0;
}
