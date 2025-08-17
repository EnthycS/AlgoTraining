#include<bits/stdc++.h>
using namespace std;


int a[60];
void initialize(){
	a[1] = 1;
	a[2] = 2;
	a[3] = 3;
	a[4] = 4;
	
	for(int i = 5; i < 60 ; i++){
		a[i] = a[i-1] +a[i-3];
	}
}
void solve(int n){
	cout<<a[n]<<endl;
}

int main(){
	int n;
	initialize();
	while(cin>>n){
		if(n == 0)break;
		solve(n);
	}
	return 0;
}
