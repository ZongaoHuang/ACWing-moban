//871. 约数之和
#include<iostream>
#include <unordered_map>
using namespace std;
typedef long long LL;
const int M = 1e9 + 7;
int main(){
	int n;
	cin >> n;
	unordered_map<int, int> primes;
	while(n --){
		int x;
		cin >> x;
		for(int i = 2; i <= x / i; i ++){
			if(x % i == 0){
				while(x % i == 0){
					x /= i;
					primes[i] ++;
				}
			}
		}
		if(x > 1)   primes[x] ++;
	}
	LL ans = 1;
	for(auto prime : primes){
		int p = prime.first,  a = prime.second;
		LL t = 1;
		while(a --){
			t = (p * t + 1) % M;
		}
		ans = ans * t % M;
	}
	cout << ans << endl;
}

