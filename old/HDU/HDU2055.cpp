#include<bits/stdc++.h>
using namespace std;

map<char,int> mp;


void init(){
	int i = 1;
	for(char t = 'A' ; t <= 'Z' ; t++){
		mp.insert(pair<char,int>(t,i));
		mp.insert(pair<char,int>(tolower(t),-i));
		i++;
	}
}
int main(){
	init();
	int t;
	cin>>t;
	int y;
	char T;
	while(t--){
		cin>>T;
		cin>>y;
		cout<<mp[T]+y<<endl;
	}
	return 0;
} 
