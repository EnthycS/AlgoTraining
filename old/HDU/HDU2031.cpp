#include<bits/stdc++.h>
using namespace std;


stack<int> s;

void GCD(int x, int y){
	int r = 1;
	while(x){
		 r = x % y;
		 s.push(r);
		 x = x / y;
	}
}

int main(){
	int flag = 0;
	int N,R;
	while(cin>>N>>R){
		flag = 0;
		if(N < 0){
			flag = 1;
			N = abs(N);
		}
		
		GCD(N,R);
		if(flag == 1)cout<<"-";
		
		while(!s.empty()){
			if(s.top() == 10){
				cout<<"A";
			}else if(s.top() == 11){
				cout<<"B";
			}else if(s.top() == 12){
				cout<<"C";
			}else if(s.top() == 13){
				cout<<"D";
			}else if(s.top() == 14){
				cout<<"E";
			}else if(s.top() == 15){
				cout<<"F";
			}else{
				cout<<s.top();
			}
			s.pop();
		}
		cout<<endl;
	} 
	
	return 0;
}
