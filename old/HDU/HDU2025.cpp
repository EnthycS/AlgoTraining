#include<bits/stdc++.h>
using namespace std;

void solve(string s){
	int len = s.size();
	char m = s[0];
	string res = "";
	for(int i = 1 ; i < len ; i++){
		if(s[i] > m){
			m = s[i];
		}
	}
	
	for(int i = 0 ; i < len ; i++){
		if(s[i] != m){
			res += s[i];
		}
		else{
			res += s[i];
			res += "(max)";
		}
	}
	
	cout<<res<<endl;
}

int main(){
	string s;
	while(cin>>s){
		solve(s);
	}
	return 0;
}
