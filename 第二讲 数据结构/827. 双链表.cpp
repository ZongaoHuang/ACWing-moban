//827. 双链表
#include<bits/stdc++.h>

using namespace std;

const int N  = 1e5 + 10;

int m, l[N], r[N], e[N], idx;

void init(){
	r[0] = 1, l[1] = 0;
	idx = 2;
}

void add(int k, int x){
	e[idx] = x;
	l[idx] = k, r[idx] = r[k];
	l[r[k]] = idx, r[k] = idx ++;
}

void remove(int k){
	l[r[k]] = l[k];
	r[l[k]] = r[k];
}

int main(){
	cin >> m;
	init();
	while(m --){
		string op;
		cin >> op;
		if(op == "L"){
			int x;
			cin >> x;
			add(0, x);
		}
		else if(op == "R"){
			int x;
			cin >> x;
			add(l[1], x);
		}
		else if(op == "D"){
			int k;
			cin >> k;
			remove(k + 1);
		}
		else if(op == "IL"){
			int k, x;
			cin >> k >> x;
			add(l[k + 1], x);
		}
		else{
			int k, x;
			cin >> k >> x;
			add(k + 1, x);
		}
	}
	for(int i = r[0]; i != 1; i = r[i]){
		cout << e[i] << " ";
	}
	return 0;
}
