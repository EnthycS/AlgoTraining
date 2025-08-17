#include<bits/stdc++.h>
using namespace std;

bool predicate(string s){
	int len = s.size();
	for(int i = 0 ; i < (len/2) ; i++){
		if(s[i] != s[len-1-i]){
			return false;
		}
	}
	return true;
}

int main(){
	int n;
	cin>>n;
	cin.ignore();
	string s;
	for(int i = 0 ; i < n ; i++){
		getline(cin,s);
		if(predicate(s)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
