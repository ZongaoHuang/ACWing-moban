//867. 分解质因数
#include<bits/stdc++.h>

using namespace std;

void divide(int n){
	for(int i = 2; i <= n / i; i ++){
		if(n % i == 0){
			int s = 0;
			while(n % i == 0){
				s ++;
				n /= i;
			}
			cout << i << " " << s << endl;
		}
	}
	if(n > 1)   cout << n << " 1" << endl;
	cout << endl;
}


int main(){
	int n;
	cin >> n;
	while(n --){
		int a;
		cin >> a;
		divide(a);
	}
	return 0;
}
