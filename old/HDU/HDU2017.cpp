#include<bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin>>n;
	string s;
	for(int i = 0 ; i < n ; i++){
		cin>>s;
		int cnt = 0;
		for(int i = 0 ; i < s.size(); i++){
			if(s[i] >= '0' && s[i] <= '9'){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
}
int main(){
	solve();
	return 0;
}
