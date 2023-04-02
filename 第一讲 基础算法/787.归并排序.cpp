//787.归并排序
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int n, a[N];

void sort1(int a[], int l, int r){
	if(l >= r)  return;
	int mid = l + r >> 1;
	sort1(a, l, mid), sort1(a, mid + 1, r);
	int i = l, j = mid + 1, k = 0, tmp[r - l + 1];
	while(i <= mid && j <= r){
		if(a[i] < a[j]) tmp[k ++] = a[i ++];
		else    tmp[k ++] = a[j ++];
	}
	while(i <= mid) tmp[k ++] = a[i ++];
	while(j <= r)   tmp[k ++] = a[j ++];
	for(int i = 0, j = l; j <= r; i ++, j ++)   a[j] = tmp[i];
}

int main(){
	cin >> n;
	for(int i = 0; i < n ; i ++){
		cin >> a[i];
	}
	sort1(a, 0, n - 1);
	for(int i = 0; i < n; i ++) cout << a[i] << " ";
	return 0;
}
