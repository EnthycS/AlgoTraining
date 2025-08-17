#include<bits/stdc++.h>
using namespace std;

long long res[51];

void initialize(){
	res[1] = 1;
	res[2] = 2;
	
	
	for(int i = 3 ; i <= 50 ; i++){
		res[i] = res[i-1] + res[i-2];
	}
}

int main(){
	int n;
	initialize();
	while(cin>>n && n){
		cout<<res[n]<<endl;
	}
	return 0;
}
