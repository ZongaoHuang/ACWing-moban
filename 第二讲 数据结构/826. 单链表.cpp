//826. 单链表
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int m, hh, e[N], ne[N], idx;

void init(){
	hh = -1;
	idx = 0;
}

void head(int x){
	e[idx] = x;
	ne[idx] = hh;
	hh = idx ++;
}

void del(int k){
	ne[k] = ne[ne[k]];
}

void ins(int k, int x){
	e[idx] = x;
	ne[idx] = ne[k];
	ne[k] = idx ++;
}

int main(){
	cin >> m;
	init();
	while(m --){
		char c;
		cin >> c;
		if(c == 'H'){
			int x;
			cin >> x;
			head(x);
		}
		else if(c == 'D'){
			int k;
			cin >> k;
			if(!k) hh = ne[hh];
			del(k - 1);
		}
		else{
			int k, x;
			cin >> k >> x;
			ins(k - 1, x);
		}
	}
	for(int i = hh; i != -1; i = ne[i]){
		cout << e[i] << " ";
	}
	return 0;
}
