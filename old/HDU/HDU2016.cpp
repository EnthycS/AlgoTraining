#include<bits/stdc++.h>
using namespace std;

int a[101];
void solve(int n){
	int min = 0;
	int t;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
		if(a[i] < a[min]){
			min = i;
		}
	}
	 t = a[0];
	a[0] = a[min];
	a[min] = t;
	
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
		if(n == 0){
			break;
		}else{
			solve(n);
		}
	}
	return 0;
}
