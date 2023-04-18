//794.高精度除法
#include<bits/stdc++.h>

using namespace std;

int r;

vector<int> div(vector<int> a, int b, int &r){
	vector<int> c;
	
	r = 0;
	for(int i = a.size() - 1; i >= 0; i --){
		r = r* 10 + a[i];
		c.push_back(r/b);
		r %= b;
	}
	reverse(c.begin(),c.end());
	
	while(c.size() > 1 && c.back() == 0)    c.pop_back();
	return c;
}

int main(){
	string a;
	int b;
	cin >> a >> b;
	vector<int> A;
	for(int i = a.size()-1; i >=0 ; i --){
		A.push_back(a[i] - '0');
	}
	
	int r;
	auto C = div(A,b,r);
	
	for(int i = C.size() - 1; i >= 0; i --){
		cout << C[i];
	}
	cout << endl << r << endl;
	return 0;
}
