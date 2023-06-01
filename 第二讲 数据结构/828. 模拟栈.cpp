//828. 模拟栈
#include<bits/stdc++.h>

using namespace std;

const int N = 1e6 + 10;

int m, skt[N], tt = 0;

void push(int x){
	skt[++tt] = x;
}

void pop(){
	tt --;
}

void empty(){
	if(tt <= 0) cout << "YES" << endl;
	else cout << "NO" << endl;
}
void query(){
	cout << skt[tt] << endl;
}
int main(){
	cin >> m;
	while(m --){
		string s;
		cin >> s;
		if(s == "push"){
			int x;
			cin  >> x;
			push(x);
		}
		else if(s == "pop"){
			pop();
		}
		else if(s == "empty"){
			empty();
		}
		else{
			query();
		}
	}
	return 0;
}
