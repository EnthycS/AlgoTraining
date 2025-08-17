#include<bits/stdc++.h>

using namespace std;

bool predicate(double a , double b , double c){
	if(a + b <= c){
		return false;
	}
	
	if(a + c <= b)return false;
	if(b + c <= a)return false;
	
	if(abs(a - b ) >= c)return false;
	if(abs(a - c ) >=  b)return false;
	if(abs(b - c )>=  a)return false;
	
	return true;
}

int main(){
	int m;
	cin>>m;
	double a , b ,c;
	while(m--){
		cin>>a>>b>>c;
		if(predicate(a,b,c)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
