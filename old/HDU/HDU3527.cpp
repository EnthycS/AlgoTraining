#include<bits/stdc++.h>
using namespace std;

int main(){
	int A,B,C;
	vector<string> in;
	vector<string> Y;
	vector<string> X;
	vector<string> res;
	while(cin>>A>>B>>C){
		in.clear();
		Y.clear();
		X.clear();
		res.clear();
		string t;
		int i = 0;
		for(i = 0 ; i < A; i++){
			cin>>t;
			in.push_back(t);
		}
		for(i = 0 ; i < B; i++){
			cin>>t;
			Y.push_back(t);
		}
		for(i = 0 ; i < C; i++){
			cin>>t;
			X.push_back(t);
		}
		
		for(i = 0 ; i < B; i++){
			if( find(in.begin(),in.end(),Y[i]) != in.end()){
				if( find(X.begin(),X.end(),Y[i]) == X.end() ){
					res.push_back(Y[i]);
				}
			}
		}
		
		if(res.size() > 0){
			for(i = 0 ;  i < res.size() ; i++){
				if(i == res.size() - 1){
					cout<<res[i]<<endl;
				}else{
					cout<<res[i]<<" ";
				}
			}
		}else{
			cout<<"No enemy spy"<<endl;
		}
		
	}
	return 0;
}
