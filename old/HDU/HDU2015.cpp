#include<bits/stdc++.h>
using namespace std;

int a[101];
void initialize(){
	a[1] = 2;
	for(int i = 2 ; i <= 100 ; i++){
		a[i] = a[i-1] + 2;
	}
}

void solve(int n , int m){
	int cnt= 0;
	vector<int> res;
	int sum = 0 ;
	for(int i = 1 ; i <= n ; i++){
		sum += a[i];
		cnt++;
		if(i == n){
			
				res.push_back((sum/cnt));
				cnt = 0;
				sum = 0;
			
		}
		else{
			if(cnt == m){
				res.push_back((sum/m));
				cnt = 0;
				sum = 0;
			}
		}
	}
	
	for(int i = 0 ; i < res.size() ; i++){
		if(i == res.size()-1){
			cout<<res[i]<<endl;
		}else{
			cout<<res[i]<<" ";
		} 
	}
}
int main(){
	initialize();
	int n , m;
	while(cin>>n>>m){
		solve(n,m);
	}
	return 0;
}
