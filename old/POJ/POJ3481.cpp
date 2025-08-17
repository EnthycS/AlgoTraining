#include<stdio.h>
#include<iostream>
#include<set>
#include<queue>
#include<cstring>
#include<map>

using namespace std;

multimap<int,int> mp;

void serve(int type){
	if(mp.empty()){
		printf("0\n");
		return;
	}
	
	multimap<int,int>::iterator it;
	if(type == 2){
		it = --mp.end();
		printf("%d\n",it->second);
		;
		mp.erase(it);
	}else if(type == 3){
		it = mp.begin();
		printf("%d\n",it->second);
		mp.erase(it);
	}
}

void add(int p , int k){
	mp.insert(make_pair(p,k));
}

int main(){
	int n , k , p;
	while(~scanf("%d",&n)){
		if(n == 0){
			break;
		}else if(n == 1){
			scanf("%d%d",&k,&p);
			add(p,k);
		}else{
			serve(n);
		}
	}
	return 0;
}
