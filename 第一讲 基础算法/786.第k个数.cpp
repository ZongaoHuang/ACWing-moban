//786.第k个数
#include<stdio.h>
#include<cmath>
#include<algorithm>
using namespace std;

const int N = 1e5 + 10;

int n,k,a[N];

int quick_sort(int a[],int l, int r, int k){
	if(l >= r)  return a[l];
	int i = l - 1, j = r + 1, x = a[l + r >> 1];
	while(i < j){
		do i ++; while(a[i] < x);
		do j --; while(a[j] > x);
		if(i < j) swap(a[i],a[j]);
	}
	if(j - l + 1 >= k){
		quick_sort(a, l, j, k);
	}
	else{
		quick_sort(a, j + 1,r, k -(j - l + 1));
	}
}

int main(){
	scanf("%d %d", &n, &k);
	for(int i = 0 ; i < n ; i ++){
		scanf("%d", &a[i]);
	}
	printf("%d",quick_sort(a, 0, n - 1, k));
	
	return 0;
}
