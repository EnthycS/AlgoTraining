#include<bits/stdc++.h>

using namespace std;
bool predicate(int y){
	int x = y;
	int a = x / 100;
	int b = (x/10)%10;
	int c = x % 10;
	
	if(x == ( (a*a*a) + (b*b*b) + (c*c*c) ) )return true;
	else return false;
}

void Print(vector<int> res){
	if(res.size() == 0)cout<<"no"<<endl;
	else{
		for(int i = 0 ; i < res.size(); i ++){
			if(i != 0)cout<<" ";
			cout<<res[i];
			
		}
	}
}

int main(){
	int m , n;
	vector<int> res;
	while(cin>>m>>n){
		res.clear();
		for(int i = m ; i <= n ; i++){
			if(predicate(i)){
				res.push_back(i);
			}
		}
		Print(res);
	}
	return 0;
}
