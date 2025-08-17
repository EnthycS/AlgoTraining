#include<bits/stdc++.h>
using namespace std;


void solve(int n){
	int a[5];
	string s ;
	cin.ignore();
	for(int i = 0 ; i < n ; i++){
		memset(a,0,sizeof(a));
		
		getline(cin,s);
		for(int j = 0 ; j < s.size() ; j++){
			if(s[j] == 'a'){
				a[0] += 1;
			}else if(s[j] == 'e'){
				a[1] += 1;
			}else if(s[j] == 'i'){
				a[2] += 1;
			}else if(s[j] == 'o'){
				a[3] += 1;
			}else if(s[j] == 'u'){
				a[4] += 1;
			}else{
				
			}
		}
		
		if(i == n-1){
			cout<<"a:"<<a[0]<<endl;
			cout<<"e:"<<a[1]<<endl;
			cout<<"i:"<<a[2]<<endl;
			cout<<"o:"<<a[3]<<endl;
			cout<<"u:"<<a[4];
		}else{
			cout<<"a:"<<a[0]<<endl;
			cout<<"e:"<<a[1]<<endl;
			cout<<"i:"<<a[2]<<endl;
			cout<<"o:"<<a[3]<<endl;
			cout<<"u:"<<a[4]<<endl;
		}
		
	}
	
}

int main(){
	int n;
	cin>>n;
	solve(n);
	return 0;
}
