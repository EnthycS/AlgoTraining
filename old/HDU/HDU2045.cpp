#include<bits/stdc++.h>
using namespace std;

long long res[51];

void initialize(){
	res[1] = 3;
	res[2] = 6;
	res[3] = 6;
	
	for(int i = 4 ; i <= 50 ; i++){
		res[i] = res[i-1] + 2*res[i-2];
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
