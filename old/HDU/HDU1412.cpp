#include<bits/stdc++.h>

using namespace std;
const int max = 10010;

set<int> A;
set<int> B;
void Print(set<int> s){
	
	for(set<int>::iterator it = s.begin() ; it != s.end() ; it++){
		if(it != s.begin())printf(" ");
		printf("%d",*it);
		
	}
	printf("\n");
}
int main(){
	int n,m;
	int t;
	while(~scanf("%d%d",&n,&m)){
		A.clear();
		for(int i = 0 ; i < n ; i++){
			scanf("%d",&t);
			A.insert(t);
		}
		for(int i = 0 ; i < m ; i++){
			scanf("%d",&t);
			A.insert(t);
		}
		Print(A);
	}
	return 0;
}

