//869. 试除法求约数
#include<bits/stdc++.h>
using namespace std;
vector<int> divi(int n){
	vector<int> ans;
	for(int i = 1; i <= n / i; i ++){
		if(n % i == 0){
			ans.push_back(i);
			if(n / i != i){
				ans.push_back(n / i);
			}
		}
	}
	sort(ans.begin(), ans.end());
	return ans;
}
int main(){
	int n;
	cin >> n;
	while(n --){
		int a;
		cin >> a;
		vector ans = divi(a);
		for(auto x : ans){
			cout << x <<  " ";
		}
		cout << endl;
	}
	return 0;
}
