#include<bits/stdc++.h>

using namespace std;

bool predicate(int x){
	if(x % 2 == 0){
		return false;
	}else{
		return true;
	}
}
int main(){
	int n,t;
	int ans ;
	while(cin>>n){
		ans = 1;
		for(int i = 0 ; i < n ; i++){
			cin>>t;
			if(predicate(t)){
				ans *= t;
			}else{
				
			}
		}
		
		cout<<ans<<endl;
		
	}
	return 0;
}
