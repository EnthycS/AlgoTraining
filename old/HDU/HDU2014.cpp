#include<bits/stdc++.h>
using namespace std;

int main(){
	double n;
	vector<int> scores;
	while(cin>>n){
		scores.clear();
		for(int i = 0 ; i < n ; i ++){
			int t ;
			cin>>t;
			scores.push_back(t);
		}
		sort(scores.begin(),scores.end());
		double sum = 0.0;
		for(int i = 1 ; i <= n-2 ; i++){
			//cout<<"score is "<<scores[i]<<endl;
			sum += scores[i];
		}
		double res = 0.0;
		res = sum / (n-2);
		printf("%.2f\n",res);
	}
	return 0;
}
