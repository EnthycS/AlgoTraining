#include<bits/stdc++.h>

using namespace std;

string s;
void solve(string s){
	int len = s.length();
	list<char> text;
	list<char>::iterator it;
	it = text.begin();
	for(int i = 0 ; i < len ; i++){
		if(s[i] == '['){
			it = text.begin();
		}
		else if(s[i] == ']'){
			it = text.end();
		}
		else{
			it = text.insert(it,s[i]);
			it ++; 
		}
		
	}
	
	for(it = text.begin() ; it != text.end() ; it++){
		cout<<*it;
	}
	s.clear();
	cout<<endl;
}

int main(){
	while(cin>>s){
		solve(s);
	}
	return 0;
}
