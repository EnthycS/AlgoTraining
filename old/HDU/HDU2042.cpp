#include<bits/stdc++.h>
using namespace std;

int a[40];

void initialize(){
	a[1] = 3;
	for(int i = 2 ; i <= 35 ; i++){
		a[i]  = 2*(a[i-1] - 1);
	}
}

int main(){
	int n;
	cin>>n;
	initialize();
	while(n--){
		int m;
		cin>>m;
		cout<<a[m+1]<<endl;
	}
	return 0;
}
