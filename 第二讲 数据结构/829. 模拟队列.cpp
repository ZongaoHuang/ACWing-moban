//829. 模拟队列
#include<bits/stdc++.h>
using namespace std;

const int N = 1e5 + 10;

int m, q[N], hh, tt;

void init(){
	hh = 0;
	tt = -1;
}

void push(int x){
	q[++ tt] = x;
}

void pop(){
	hh ++;
}

void empty(){
	if(hh <= tt)    cout << "NO" << endl;
	else    cout << "YES" << endl;
}

void query(){
	cout << q[hh] << endl;
}
int main(){
	cin >> m;
	init();
	while(m --){
		string op;
		cin >> op;
		int x;
		if(op == "push"){
			cin >> x;
			push(x);
		}
		else if(op == "pop"){
			pop();
		}
		else if(op == "empty"){
			empty();
		}
		else{
			query();
		}
	}
	return 0;
}
