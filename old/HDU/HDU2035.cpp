#include<bits/stdc++.h>

using namespace std;

void solve(int a , int b){
	int res = 1;
	for(int i = 0 ; i < b  ; i++){
		res = (res * a) % 1000;
	}
	cout<<res<<endl;
}

int main(){
	int A,B;
	while(cin>>A>>B){
		if(A == 0 && B == 0){
			break;
		}
		solve(A,B);
	}
	return 0;
}
