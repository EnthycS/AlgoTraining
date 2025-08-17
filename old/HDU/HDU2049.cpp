#include<bits/stdc++.h>
using namespace std;
const int MAX = 25;

long long f[MAX];
long long c[MAX][MAX];

void init(){
	f[1] = 0;
	f[2] = 1;
	for(int i = 3 ; i < MAX ; i++){
		f[i] = (i-1)*(f[i-1] +f[i-2]);
		
	}
	for(int i = 0 ; i < MAX ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j == 0){
				c[i][j] = 1;
			}else{
				c[i][j] = c[i-1][j] +c[i-1][j-1];
			}
		} 
	}
} 
int main(){
	init();
	int C;
	cin>>C;
	while(C--){
		int n,m;
		cin>>n>>m;
		cout<<c[n][m]*f[m]<<endl;
	}
	return 0;
}
