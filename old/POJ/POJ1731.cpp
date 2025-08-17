#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string.h>

using namespace std;

int main(){
	int i,n;
	string s;
	while(cin>>s){
		
		sort(s.begin(),s.end());
		cout<<s<<endl;
		while(next_permutation(s.begin(),s.end())){
			cout<<s<<endl;
		}
	}
	return 0;
}
