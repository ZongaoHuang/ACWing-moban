//873. 欧拉函数
#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin >> n;
	while(n --){
		int x;
		cin >> x;
		int res = x;
		for(int i = 2; i <= x / i; i ++){
			if(x % i == 0){
				res = res / i * (i - 1);
				while(x % i == 0)   x /= i;
			}
		}
		if(x > 1)   res = res / x * (x - 1);
		cout << res << endl;
	}
	return 0;
}
