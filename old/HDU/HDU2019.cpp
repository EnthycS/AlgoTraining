#include<bits/stdc++.h>
using namespace std;

int a[110];

void solve(int n,int m){
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	
	int insertPos = n;
	for(int i = 0 ; i < n ; i++){
		if(a[i] > m){
			insertPos = i;
			break;
		}
	}
	if(insertPos == n){
		a[n] = m;
	}else{
		for(int i = n-1 ; i >= insertPos ; i--){
			a[i+1] = a[i];
		}
		a[insertPos] = m;
	}
	
	for(int i = 0 ; i <= n ; i++){
		if(i == n){
			cout<<a[i]<<endl;
		}
		else{
			cout<<a[i]<<" ";
		}
	}
}
int main(){
	
	int n,m;
	while(cin>>n>>m){
		if(n == 0 && m == 0)break;
		solve(n,m);
	}
	return 0;
}
