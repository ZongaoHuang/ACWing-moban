//839. 模拟堆
#include<bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10;

int h[N], ph[N], hp[N];
int size1;

void heap_swap(int a, int b){
	swap(ph[hp[a]], ph[hp[b]]);
	swap(hp[a], hp[b]);
	swap(h[a], h[b]);
}

void down(int t){
	int u = t;
	if(t * 2 <= size1 && h[u] > h[t * 2])   u = t * 2;
	if(t * 2 + 1 <= size1 && h[u] > h[t * 2 + 1])   u = t * 2 + 1;
	if(u != t){
		heap_swap(u, t);
		down(u); 
	}
}

void up(int t){
	while(t / 2 && h[t / 2] > h[t]){
		heap_swap(t / 2, t);
		t /= 2;
	}
}
int main(){
	int n;
	cin >> n;
	int m = 0;
	while(n --){
		string op;
		cin >> op;
		if(op == "I"){
			int x;
			cin >> x;
			size1 ++;
			m ++;
			ph[m] = size1, hp[size1] = m;
			h[size1] = x;
			up(size1);
		}
		else if(op == "PM") cout << h[1] << endl;
		else if(op == "DM"){
			heap_swap(1, size1);
			size1 --;
			down(1);
		}
		else if(op == "D"){
			int k;
			cin >> k;
			k = ph[k];
			heap_swap(k, size1);
			size1 --;
			down(k), up(k);
		}
		else{
			int k, x;
			cin >> k >> x;
			k = ph[k];
			h[k] = x;
			down(k);
			up(k);
		}
	}
	return 0;
}
