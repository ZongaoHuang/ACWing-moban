//872. 最大公约数
#include<bits/stdc++.h>

using namespace std;

int gcd(int a, int b){
	return b ? gcd(b, a % b) : a;
}

int main(){
	int n;
	cin >> n;
	while(n --){
		int a, b;
		cin >> a >> b;
		cout << gcd(a, b) << endl;
	}
	return 0;
}
