#include<bits/stdc++.h>
using namespace std;
const int MAX = 10010;

long long f[MAX];

void init(){
	f[1] = 2;
	f[2] = 7;
	for(int i = 3 ; i < MAX ; i++){
		f[i] = 4*i - 3 + f[i-1];
	}
}
int main(){
	int c;
	cin>>c;
	init();
	while(c--){
		int n;
		cin>>n;
		cout<<f[n]<<endl;
	}
	return 0;
}
