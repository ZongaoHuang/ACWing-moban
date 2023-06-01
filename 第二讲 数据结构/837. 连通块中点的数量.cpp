//837. 连通块中点的数量
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int n, m, p[N], s[N];

int find(int x){
	if(p[x] != x)   p[x] = find(p[x]);
	return p[x];
}
int main(){
	cin >> n >> m;
	for(int i = 1; i <= n; i ++){
		p[i] = i;
		s[i] = 1;
	}
	while(m --){
		string op;
		cin >> op;
		int a , b;
		if(op == "C"){
			cin >> a >> b;
			int pa = find(a), pb = find(b);
			if(pa != pb){
				s[pb] += s[pa];
				p[pa] = pb;
			}
		}
		else if(op == "Q1"){
			cin >> a >> b;
			if(find(a) != find(b))  cout << "No" << endl;
			else cout << "Yes" << endl;
		}
		else{
			cin >> a;
			cout << s[find(a)] << endl;
		}
	}
	return 0;
}
