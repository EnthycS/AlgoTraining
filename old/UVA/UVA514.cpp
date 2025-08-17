#include<bits/stdc++.h>

using namespace std;
const int MAX = 1005;

int b[MAX];

int main(){
	int n;
	while(cin>>n){
		if(n == 0)break;
		while(true){
			int i = 1;
			int j = 1;
			cin>>b[1];
			if(b[1] == 0){
				break;
			}
			
			for(int k = 2 ; k <= n ; k++){
				cin>>b[k];
			}
			
			stack<int> C;
			while(i <= n){
				if(i == b[j]){
					i++;
					j++;
				}else{
					C.push(i++);
				}
				
				while(!C.empty() && C.top() == b[j]){
					j++;
					C.pop();
				}
					
			}
			
			if(j <= n){
				cout<<"No"<<endl;
			}else{
				cout<<"Yes"<<endl;
			}
			
			
		}
		
		cout<<endl;
	}
	return 0;
}
