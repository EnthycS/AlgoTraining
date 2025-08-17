#include<bits/stdc++.h>

using namespace std;

struct Pair{
	int a,b;
	Pair(){
	}
};

int cmp1(Pair p1, Pair p2){
	return p1.b < p2.b;
}
int main(){
	
	int n;
	while(cin>>n && n){
		Pair p[105];
		for(int i = 0; i < n; i++) {
			int x, y; 
			cin>>x>>y;
			p[i].a = x;  
			p[i].b = y;
		}
		
		sort(p,p+n,cmp1);
		int sum = 1;
		int flag = p[0].b;
		
		for(int i = 0 ; i < n ; i++){
			if(p[i].a >= flag){
				flag = p[i].b;
				sum++;
			}
			
			
		}
		
		cout<<sum<<endl;
		
	}
	return 0;
}
