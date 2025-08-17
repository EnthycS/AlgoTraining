#include<bits/stdc++.h>

using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> a;
	for(int i = 0 ; i < n ; i++){
		int t;
		cin>>t;
		a.push_back(t);
	}
	char op;
	int x,y;
	
	while(k--){
		cin>>op;
		if(op == 'D'){
			cin>>x;
			if(x >= a.size()){
				continue;
			}else{
				a.erase(a.begin()+x);
			}
		}else{
			cin>>x>>y;
			if( x >= a.size()){
				a.push_back(y);
			}else{
				a.insert(a.begin()+x,y);
			}
		}
		
	}
	cout<<a.size()<<endl;
	for(int i = 0 ; i < a.size() ; i++){
		if(i != 0)cout<<" ";
		cout<<a[i];
	}
	return 0;
}
