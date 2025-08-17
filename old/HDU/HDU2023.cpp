#include<bits/stdc++.h>
using namespace std;



void solve(int n,int m){
	int a[n][m];
	int cnt = 0;
	double res1[n];
	double res2[m];
	double sum1 = 0.0;
	double sum2 = 0.0;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			cin>>a[i][j];
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		sum1 = 0.0;
		for(int j = 0 ; j < m ; j++){
			sum1 += a[i][j];
			
		}
		res1[i] = sum1 / m;
	}
	
	for(int i = 0 ; i < m ; i++){
		sum2 = 0.0;
		for(int j = 0 ; j < n ; j++){
			sum2 += a[j][i];
			
		}
		res2[i] = sum2 / n;
	}
	
	for(int i = 0 ; i < n ; i++){
		bool flag = true;
		for(int j = 0 ;j < m ; j++){
			if(a[i][j] < res2[j]){
				flag = false;
				break;
			}
		}
		
		if(flag){
			cnt++;	
		}else{
			
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		if( i == n-1){
			printf("%.2lf\n",res1[i]);
		}else{
			printf("%.2lf ",res1[i]);
		}
	}
	
	for(int i = 0 ; i < m ; i++){
		if( i == m-1){
			printf("%.2lf\n",res2[i]);
		}else{
			printf("%.2lf ",res2[i]);
		}
	}
	
	cout<<cnt<<endl<<endl;
	
}

int main(){
	int n,m;
	while(cin>>n>>m){
		solve(n,m);
		
	}
	return 0;
}
