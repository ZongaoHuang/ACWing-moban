//791.高精度加法
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
vector<int> a1, b1;

vector<int> add(vector<int> a, vector<int> b){
	if(a.size() < b.size()) return add(b,a);
	vector<int> c;
	int t = 0;
	for(int i = 0; i < a.size(); i ++){
		t += a[i];
		if(i < b.size())    t += b[i];
		c.push_back(t % 10);
		t /= 10;
	}
	if(t)   c.push_back(t);
	return c;
} 


int main(){
	string a,b;
	cin >> a >> b;
	for(int i = a.size() - 1; i >= 0; i --) a1.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i --) b1.push_back(b[i] - '0');
	vector<int> c;
	c = add(a1, b1);
	for(int i = c.size() - 1; i >= 0; i --) cout << c[i];
	return 0;
}
