//870. 约数个数
#include<bits/stdc++.h>

using namespace std;

const int N = 1e9 + 7;
const int M = 1e5 + 10;
int n;
int main(){
	cin >> n;
	unordered_map<int, int> hash;
	while(n --){
		int a;
		cin >> a;
		for(int i = 2; i <= a / i; i ++){
			if(a % i == 0){
				while(a % i == 0){
					hash[i] ++;
					a /=  i;
				}
			}
		}
		if(a > 1)   hash[a] ++;
	}
	long long ans = 1;
	for(auto t : hash){
		ans = ans * (t.second + 1) % N; 
	}
	cout << ans;
	return 0;
}
