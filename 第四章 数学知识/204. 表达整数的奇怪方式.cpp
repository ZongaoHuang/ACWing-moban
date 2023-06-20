//204. 表达整数的奇怪方式
#include<bits/stdc++.h>

using namespace std;

typedef long long LL;

LL exgcd(LL a, LL b, LL &x, LL &y){
	if(!b){
		x = 1, y = 0;
		return a;
	}
	int d = exgcd(b, a % b, y, x);
	y -= a / b * x ;
	return d;
}

int main(){
	int n;
	cin >> n;
	
	bool has_answer = true;
	LL a1, m1;
	cin >> a1 >> m1;
	for(int i = 0; i < n - 1; i ++){
		LL a2, m2;
		cin >> a2 >> m2;
		LL k1, k2;
		LL d = exgcd(a1, a2, k1, k2);
		if((m2 - m1) % d){
			has_answer = false;
			break;
		}
		
		k1 *= (m2 - m1) / d;
		LL t = a2 / d;
		k1 = (k1 % t + t) % t; 
		m1 = a1 * k1 + m1;
		a1 = abs(a1 / d * a2);
		
	}
	
	if(has_answer){
		cout <<(m1 % a1 + a1) % a1 << endl;
	}
	else{
		cout << "-1" << endl;
	}
	return 0;
}
