#include<bits/stdc++.h>
using namespace std;

long long res[41];

void initialize(){
	res[1] = 3;
	res[2] = 8;
	for(int i = 3 ; i <= 40 ; i++){
		res[i] = 2*res[i-2] + 2*res[i-1];
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
