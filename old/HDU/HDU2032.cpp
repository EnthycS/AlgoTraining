#include<bits/stdc++.h>

using namespace std;


int a[31][31];

void initialize(){
	for(int i = 0 ; i < 31 ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j == 0 || j == i){
				a[i][j] = 1;
			}else{
				a[i][j] = a[i-1][j] + a[i-1][j-1];
			}
		}
	}
}

void solve(int n){
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j <= i ; j++){
			if(j == i){
				cout<<a[i][j];
			}else{
				cout<<a[i][j]<<" ";
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
int main(){
	initialize();
	int n;
	while(cin>>n){
		solve(n);
	}
	return 0;
}
