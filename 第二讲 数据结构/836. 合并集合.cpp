//836. 合并集合
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m;
int p[N];
int find(int x){
	if(p[x] != x)   p[x] = find(p[x]);
	return p[x];
}

int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++)    p[i] = i;
	while(m --){
		string op;
		int a, b;
		cin >> op >> a >> b;
		if(op == "M"){
			a = find(a);
			b = find(b);
			if(a != b){
				p[b] = a;
			}
		}
		else{
			if(find(a) != find(b)){
				cout << "No" << endl;
			}
			else    cout << "Yes" << endl;
		}
	}
	return 0;
}
