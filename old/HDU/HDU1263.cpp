#include<bits/stdc++.h>
using namespace std;

map<string, map<string,int> >mp;

int main(){
	
	int N,M;
	scanf("%d",&N);
	while(N--){
		scanf("%d",&M);
		mp.clear();
		string s1,s2;
		int amount;
		while(M--){
			//scanf("%s%s%d",&s1,&s2,&amount);
			cin>>s1>>s2>>amount;
			mp[s2][s1] += amount;
		}
		
		map<string, map<string,int> >::iterator it1;
		map<string,int>:: iterator it2;
		
		for(it1 = mp.begin() ; it1 != mp.end() ; it1++){
			cout<<it1->first<<endl;
			for(it2 = it1->second.begin() ; it2 != it1->second.end() ; it2++){
				cout<<"   |----"<<it2->first<<"("<<it2->second<<")"<<endl;
			}
		}
		if(N)cout<<endl;
		
	}
	return 0;
}
