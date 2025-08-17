#include<bits/stdc++.h>
using namespace std;

long long quickPower(long long base , long long power){
	long long res = 1;
	while(power){
		if(power%2){
			res = res * base % 100;
		}
		base = base * base % 100;
		power = power / 2;
	}
	
	return res;
}

int main(){
	int T;
	while(cin>>T){
		
		for(int i = 1 ; i <= T ; i++){
			long long N;
			cin>>N;
			cout<<"Case "<<i<<": "<<( quickPower(4,N-1) + quickPower(2,N-1) )%100<<endl;
		}
		cout<<endl;
	}
	return 0;
}
