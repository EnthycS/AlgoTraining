#include<stdio.h>
#include<iostream>
#include<set>
#include<queue>
#include<cstring>
using namespace std;

bool vis[10005];
multiset<int>s;

int k;
void del(int p){
	if(s.empty()){
		cout<<"-1"<<endl;
		return;
	}
	
	if(p == 1){
		if(vis[k++]){
			cout<<*s.begin()<<endl;
		}
		s.erase(*s.begin());
	}else{
		if(vis[k++]){
			cout<<*s.rbegin()<<endl;
		}
		s.erase(*s.rbegin());
	}
}

int main(){
	char c;
	int m,n,x,p;
	while(cin>>m>>n){
		memset(vis,false,sizeof(vis));
		s.clear();
		for(int i = 0 ; i < n ; i++){
			cin>>x;
			vis[x] = true;
		}
		
		p = 1;
		k = 1;
		while(cin>>c){
			if(c == 'e'){
				break;
			} else if(c == 'a'){
				cin>>x;
				s.insert(x);
			}else if(c == 'p'){
				cin>>x;
				p = x;
			}else if(c == 'r'){
				del(p);
			}
		}
		cout<<endl;
	}
	return 0;
}
