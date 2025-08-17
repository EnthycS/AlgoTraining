#include<bits/stdc++.h>

using namespace std;
int a[101];


void solve(int n){
	for(int i = 0 ; i < 2*n ; i++){
		cin>>a[i];
	}
	
	double res = 0.0;
	for(int i = 0 ; i < 2*n - 3; i += 2){
		res += a[i+2]*a[i+1] - a[i]*a[i+3];
		//cout<<"res is "<<res<<endl;
	}
	res += a[0]*a[2*n-1] - a[2*n-2]*a[1];
	res = abs(res/2.0);
	printf("%.1lf\n",res);
}

int main(){
	int n;
	while(cin>>n){
		if(n == 0)break;
		solve(n);
	}
	return 0;
}
