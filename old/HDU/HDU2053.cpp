#include<bits/stdc++.h>
using namespace std;

int predicate(int n){
	int res = -1;
	for(int i = 1 ;;i++){
		if(i > n){
			break;
		}else{
			if((n % i) == 0){
				res = -res;
			}
		}
	}
	
	return res;
}

int main(){
	int n;
	while(cin>>n){
		if( predicate(n) == 1 ){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	return 0;
}
