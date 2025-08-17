#include<bits/stdc++.h>

using namespace std;

struct Matrix{
	int m;
	int n;
	
};

map<char,Matrix> mp;
int main(){
	int len;
	cin>>len;
	char name;
	int m1,n1;
	int sum = 0;
	int n = len;
	while(len--){
		cin>>name>>m1>>n1;
		struct Matrix temp;
		temp.m = m1;
		temp.n = n1;
		mp[name] = temp;
	}
	string s;
	while(cin>>s){
		bool flag = false;
		stack<int> ss;
		int len1 = s.size();
		sum = 0;
		for(int i = 0 ; i < len1; i++){
			if(isalpha(s[i])){
				ss.push(s[i]);
			}else if(s[i] == ')'){
				char b = ss.top();
				ss.pop();
				char a = ss.top();
				ss.pop();
				if(mp[b].m == mp[a].n){
					sum += mp[a].m * mp[b].n * mp[a].n;
					mp['A'+n].m = mp[a].m;
					mp['A'+n].n = mp[b].n;
					ss.push((char)('A'+n++));
				}else{
					cout<<"error"<<endl;
					flag = !flag;
					break;
				}
			}
		}
		
		if(!flag){
			cout<<sum<<endl;
		}
	}
	return 0;
}
