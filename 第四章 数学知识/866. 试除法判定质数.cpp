//866. 试除法判定质数
#include<bits/stdc++.h>

using namespace std;
int n;
bool is_prime(int n){
	if(n < 2)  return false;
	for(int i = 2; i <= n / i; i ++){
		if(n % i == 0) return false;
	}
	return true;
}

int main(){
	cin >> n;
	while(n --){
		int x;
		cin >> x;
		if(is_prime(x)) cout << "Yes" << endl;
		else cout << "No" << endl;
	}
	return 0;
}
