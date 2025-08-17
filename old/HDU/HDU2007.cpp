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
	int n,m,t;
	int ans1,ans2 ;
	while(cin>>m>>n){
		ans1 = 0;
		ans2 = 0;
		if(n < m){
			t = n;
			n = m ;
			m = t;
		}
		
		for(int i = m ; i <= n ; i++){
			
			if(predicate(i)){
				ans2 += (i*i*i);
			}else{
				ans1 += (i*i);
			}
		}
		
		cout<<ans1<<" "<<ans2<<endl;
		
	}
	return 0;
}
