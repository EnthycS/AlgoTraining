#include<bits/stdc++.h>
using namespace std;

int a[50];

void initialize(){
	a[1] = 1;
	a[2] = 1;
	for(int i = 3 ; i <= 41 ; i++){
		a[i] = a[i-1] + a[i-2];
	} 
}

int main(){
	int n;
	cin>>n;
	initialize();
	
	while(n--){
		int m;
		cin>>m;
		cout<<a[m]<<endl;
	}
	return 0;
}
