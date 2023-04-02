//785.快速排序
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, a[N];

void quick_sort(int a[], int l, int r){
	if(l >= r)  return;
	int i = l - 1, j = r + 1, mid = a[l + r >> 1];
	while(i < j){
		do i ++; while(a[i] < mid);
		do j --; while(a[j] > mid);
		if(i < j)   swap(a[i], a[j]);
	}
	quick_sort(a, l, j), quick_sort(a, j + 1, r);
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		cin >> a[i];
	}
	quick_sort(a, 0, n - 1);
	for(int i = 0; i < n; i ++){
		cout << a[i] << " ";
	}
	return 0;
}
