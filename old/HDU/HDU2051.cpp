#include<bits/stdc++.h>
using namespace std;

void decimal_trans_to_binary(int n){
	stack<int> s;
	s.push(n%2);
	n = n / 2;
	while( n != 0){
		s.push(n % 2);
		n = n/2;
	}
	
	
	while(!s.empty()){
		int t = s.top();
		
		cout<<t;
		s.pop();
		
	}
	cout<<endl;
	
}

int main(){
	int n;
	while(cin>>n){
	 	decimal_trans_to_binary(n);
	} 
	return 0;
}
