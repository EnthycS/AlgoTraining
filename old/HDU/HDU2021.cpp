#include<bits/stdc++.h>
using namespace std;

int a[110];

int money[6] = {100,50,10,5,2,1};

void solve(int n){
	int cnt = 0;
	for(int i = 0 ; i < n ; i++){
		cin>>a[i];
	}
	
	for(int i = 0 ; i < n ; i++){
		int pos = 0;
		while(a[i] > 0){
			if(a[i] >= money[pos]){
				a[i] = a[i] - money[pos];
				cnt++;
			}else{
				pos++;
			}
		}
	}
	
	cout<<cnt<<endl;
		
}


int main(){
	int n;
	while(cin>>n){
		if(n == 0){
			break;
		}
		solve(n);
	}
	return 0;
}
