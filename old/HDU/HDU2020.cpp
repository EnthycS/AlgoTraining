#include<bits/stdc++.h>
using namespace std;

int a[110];
void solve(int n){
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	
	int t;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < n - i - 1 ; j++ ){
			if(abs(a[j]) < abs(a[j+1])){
				t = a[j];
				a[j] = a[j+1];
				a[j+1] = t;
			}
		}
	}
	
	for(int i = 0 ; i < n ; i++){
		if(i == n-1){
			cout<<a[i]<<endl;
		}else{
			cout<<a[i]<<" ";
		}
	}
}
int main(){
	int n;
	while(cin>>n){
		if( n == 0)break;
		solve(n);
	}
	return 0;
}
