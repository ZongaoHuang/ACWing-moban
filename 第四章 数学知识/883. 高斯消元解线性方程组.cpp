//883. 高斯消元解线性方程组
#include<bits/stdc++.h>
using namespace std;

const int N = 110;
const double eps = 1e-6;
int n;
double a[N][N];

void out(){
	for(int i = 0; i < n ; i ++){
		for(int j = 0; j < n; j ++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}
int gauss(){
	int c, r;
	for(c = 0, r = 0; c < n; c ++){
		int t = r;
		for(int i = r; i < n; i ++){
			if(fabs(a[i][c]) > fabs(a[t][c])){
				t = i;
			}
		}
		if(fabs(a[t][c]) < eps) continue;
		for(int i = c; i < n + 1; i ++) swap(a[t][i], a[r][i]);
		for(int i = n; i >= c; i --)    a[r][i] /= a[r][c];
		for(int i = r + 1; i < n; i ++){
			if(fabs(a[i][c]) > eps){
				for(int j = n; j >= c; j --){
					a[i][j] -= a[r][j] * a[i][c];
				}
			}
		}
		r ++;
		//out();
	}
	if(r < n){
		for(int i = r; i < n; i ++){
			if(fabs(a[i][n]) > eps){
				return 2;
			}
		}
		return 1;
	}
	for(int i = n - 1; i >= 0; i --){
		for(int j = i + 1; j < n; j ++){
			a[i][n] -= a[j][n] * a[i][j];
		}
	}
	return 0;
}

int main(){
	cin >> n;
	for(int i = 0; i < n; i ++){
		for(int j = 0; j < n + 1; j ++){
			cin >> a[i][j];
		}
	}
	int t = gauss();
	if(t == 0){
		for(int i = 0; i < n; i ++) printf("%.2lf\n", a[i][n]);
	}
	else if(t == 1) cout << "Infinite group solutions" << endl;
	else cout << "No solution" << endl;
	return 0;
	
}
