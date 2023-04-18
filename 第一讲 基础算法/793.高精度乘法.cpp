//793.高精度乘法
#include<bits/stdc++.h>

using namespace std;

vector<int> mul(vector<int> a, int b){
	vector<int> c;
	int t = 0;
	for(int i = 0; i < a.size() || t; i ++){
		if(i < a.size()){
			t += a[i] * b;
		}
		c.push_back(t % 10);
		t /= 10;
	}
	while(c.back() == 0)    c.pop_back();
	return c;
}

int main(){
	string a;
	int b;
	cin >> a >> b;
	if(a == "0" || b == 0){
		cout << "0";
	}
	else{
		vector<int> A;
		for(int i = a.size() - 1; i >= 0; i --) A.push_back(a[i] - '0');
		auto C = mul(A, b);
		for(int i = C.size() - 1; i >= 0; i --) cout << C[i];
	}
	return 0;
}
