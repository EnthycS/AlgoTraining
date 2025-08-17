#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	int countNeg,countZero,countPos;
	while(cin>>n){
		if(n == 0)break;
		countNeg = 0;
		countZero = 0;
		countPos = 0;
		
		double t;
		for(int i = 0 ; i < n ; i++){
			cin>>t;
			if(t < 0){
				countNeg++;
			}else if(t == 0){
				countZero++;
			}else{
				countPos++;
			}
		}
		
		cout<<countNeg<<" "<<countZero<<" "<<countPos<<endl;
		
	}
	return 0;
}
