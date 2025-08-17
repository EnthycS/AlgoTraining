#include<bits/stdc++.h>

using namespace std;
int main(){
	char a,b,c;
	while(cin>>a>>b>>c){
		if(a<b){
			if(b < c){
				cout<<a<<" "<<b<<" "<<c<<endl;
			}else{
				if(a<c){
					cout<<a<<" "<<c<<" "<<b<<endl;
				}else{
					cout<<c<<" "<<a<<" "<<b<<endl;
				}
			}
		}else{
			if(a<c){
				cout<<b<<" "<<a<<" "<<c<<endl;
			}else{
				if(b<c){
					cout<<b<<" "<<c<<" "<<a<<endl;
				}else{
					cout<<c<<" "<<b<<" "<<a<<endl;
				}
			}
		}
	}
	return 0;
}
