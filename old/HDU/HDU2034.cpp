#include<bits/stdc++.h>

using namespace std;

vector<int> A;
vector<int> B;
void solve(int n , int m){
	A.clear();
	B.clear();
	int t;
	for(int i = 0 ; i < n ; i++){
		cin>>t;
		A.push_back(t);
	}
	for(int i = 0 ; i < m ; i++){
		cin>>t;
		A.erase(remove(A.begin(),A.end(),t),A.end());
	}
	
	sort(A.begin(),A.end());
	if(A.empty()){
		cout<<"NULL"<<endl;
	}else{
		for(int i = 0 ; i < A.size() ; i++){
			if( i == A.size() - 1){
				cout<<A[i];
			}else{
				cout<<A[i]<<" ";
			}
		}
		cout<<endl;
		
	}
	
	
	

}

int main(){
	int n,m;
	while(cin>>n>>m){
		if(n == 0 && m == 0){
			break;
		}
		solve(n,m);
	}
	return 0;
} 
