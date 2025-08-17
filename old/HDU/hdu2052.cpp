#include<bits/stdc++.h>
using namespace std;

void draw(int n,int m){
	int m1 = m + 2;
	int n1 = n + 2;
	for(int i = 0 ; i < m1 ; i++){
		for(int j = 0 ; j < n1 ; j++){
			//cout<<"pos : "<<i<<" "<<j<<endl<<endl;
			if(i == 0 || i == m1 - 1){
				if(j == 0 || j == n1 - 1){
					printf("+");
					
				}else{
					printf("-");
				}
			}else{
				if(j == 0 || j == n1 - 1){
					printf("|");
					
				}else{
					printf(" ");
				}
			}
			
			
		}
		printf("\n");
	}
	
	//cout<<endl;
}

int main(){
	int n,m;
	while(cin>>n>>m){
		draw(n,m);
	}
	return 0;
}
