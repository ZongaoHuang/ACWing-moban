//845. 八数码
#include<bits/stdc++.h>

using namespace std;

void dfs(string s){
	string e = "12345678x";
	queue<string> q;
	unordered_map<string, int> d;
	
	q.push(s);
	d[s] = 0;
	
	int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, -1, 0, 1};
	
	while(q.size()){
		auto t = q.front();
		q.pop();
		if(t == e){
			cout << d[t] << endl;
			return;
		}
		int dis = d[t];
		int k = t.find('x');
		int x = k / 3, y = k % 3;
		for(int i = 0; i < 4; i ++){
			int a = x + dx[i], b = y + dy[i];
			if(a >= 0 && a < 3 && b >= 0 && b < 3){
				swap(t[k], t[a * 3 + b]);
				if(!d.count(t)){
					d[t] = dis + 1;
					q.push(t);
				}
				swap(t[k], t[a * 3 + b]);
			}
		}
	}
	cout << "-1" <<endl;
}

int main(){
	string s;
	for(int i = 0; i < 9; i ++){
		char c;
		cin >> c;
		s += c;
	}
	dfs(s);
	return 0;
}
