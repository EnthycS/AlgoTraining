#include<bits/stdc++.h>
using namespace std;

void solve(int m , int n){
	long a[m][n];
	for(int i  = 0 ; i < m ; i++){
		for(int j = 0 ; j < n  ; j++){
			cin>>a[i][j];
		}
	}
	
	int maxX = 0;
	int maxY = 0;
	for(int i  = 0 ; i < m ; i++){
		for(int j = 0 ; j < n  ; j++){
			if(abs(a[i][j]) > abs(a[maxX][maxY]) ){
				maxX = i;
				maxY = j;
			}
		}
	}
	
	cout<<maxX+1<<" "<<maxY+1<<" "<<a[maxX][maxY]<<endl;
	
	
}


int main(){
	int m,n;
	while(cin>>m>>n){
		solve(m,n);
	}
	return 0;
}
