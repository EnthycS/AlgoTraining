#include<bits/stdc++.h>
using namespace std;


int getScores(int left,int score1){
	int res = score1;
	if(left > 6){
		res += (left-6)*1 + (left-6)*7 + 2 + 3 + 4 + 5 + 6 + 7;
	}else{
		res += 7*left - (left*(left-1))/2;
	}
	
	return res;
}
int main(){
	int left,score1,score2;
	int n;
	cin>>n;
	while(n--){
		cin>>left>>score1>>score2;
		int score_p = getScores(left,score1);
		if(score_p >= score2){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
	
	return 0;
}
