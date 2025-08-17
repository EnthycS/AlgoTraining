#include<bits/stdc++.h>
using namespace std;
const int MAX = 1001;

double getRabbitTime(int L , int VR){
	double res  = 0.0;
	res = (double)(L/VR);
	//cout<<"Rabbit :"<<res<<endl;
	return res;
}

double getTurtleTime(int L , double vt1 , double vt2 , double c , double *a,int N,double T){
	
	double dp[MAX];
	fill(dp,dp+MAX,99999999);
	dp[0] = 0;
	a[0] = 0;
	a[N+1] = L;
	for(int i = 1 ; i <= N+1; i++){
		for(int j = 0 ; j < i ; j++){
			if(a[i] - a[j] < c){
				dp[i] = min(dp[i],dp[j] + (a[i] - a[j])/vt1 + (j==0?0:T));
			}else{
				dp[i] = min(dp[i],dp[j] + (c/vt1) + (a[i]-a[j]-c)/vt2 + (j==0?0:T));
			}
		}
	}
	
	return dp[N+1];
	
}
int main(){
	int L;
	double a[MAX];
	double VR;
	double vt1,vt2,C,T;
	int N;
	
	while(cin>>L){
		cin>>N>>C>>T;
		cin>>VR>>vt1>>vt2;
		for(int i = 1 ; i <= N ; i++){
			cin>>a[i];
		}
		
		double RabbitTime = getRabbitTime(L,VR);
		double TurtleTime = getTurtleTime(L,vt1,vt2,C,a,N,T);
		
		if(RabbitTime < TurtleTime){
			cout<<"Good job,rabbit!"<<endl;
		}else{
			cout<<"What a pity rabbit!"<<endl;
		}
	}
	
	return 0;
}
