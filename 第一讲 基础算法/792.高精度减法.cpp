//792.高精度减法

#include<bits/stdc++.h>

using namespace std;

bool cmp(vector<int> a, vector<int> b){
	if(a.size()!= b.size()) return a.size() > b.size();
	else{
		for(int i = a.size() - 1; i >= 0; i --) {
			if(a[i] != b[i])    return a[i] > b[i];
		}
		return true;
	}
}


void sub(vector<int> a, vector<int> b){
	vector<int> c;
	for(int i = 0, t = 0; i < a.size(); i ++){
		t = a[i] - t;
		if(i < b.size())
			t -= b[i];
		c.push_back((t + 10) % 10);
		if(t>=0)   t = 0;
		else t = 1;
	}
	while(c.size() > 1 && c.back() == 0)    c.pop_back();
	for(int i = c.size() - 1; i >= 0; i --) cout << c[i];
	
}
int main(){
	
	string a, b;
	cin >> a >> b;
	vector<int> a1, b1;
	for(int i = a.size() - 1; i >= 0; i --) a1.push_back(a[i] - '0');
	for(int i = b.size() - 1; i >= 0; i --) b1.push_back(b[i] - '0');
	if(cmp(a1, b1)){
		sub(a1, b1);
	}
	else{
		cout << "-";
		sub(b1, a1);
	}
	return 0;
}
