#include<bits/stdc++.h>
using namespace std;

bool predicate(string s){
	int a[4];
	memset(a,0,sizeof(a));
	int len = s.size();
	if(len < 8 || len > 16){
		return false;
	}else{
		for(int i = 0 ; i < len ; i++){
			if(s[i] >= 'A' && s[i] <= 'Z'){
				a[0]++;
			}else if(s[i] >= 'a' && s[i] <= 'z'){
				a[1]++;
			}else if(s[i] >= '0' && s[i] <= '9'){
				a[2]++;
			}else if(s[i] == '~' || s[i] == '!' || s[i] == '@' || s[i] == '#'|| s[i] == '$'|| s[i] == '%'|| s[i] == '^'){
				a[3]++;
			}else{
				
			}
			
		}
		
		int cnt = 0;
		for(int i = 0 ; i < 4 ; i++){
			if(a[i] != 0)cnt++;
		}
		if(cnt >= 3){
			return true;
		}else{
			return false;
		}
	}
}

int main(){
	int n;
	cin>>n;
	string s;
	while(n--){
		cin>>s;
		if(predicate(s)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
