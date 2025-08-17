#include<bits/stdc++.h>

using namespace std;
double arr[1001];
void Sum(){
	
	int temp = 1;
	int sign = 1;
	for(int i = 1 ; i <= 1000 ; i++){
		if(i == 1){
			arr[i] = 1;
			sign = -sign;
			
		}else{
			
			arr[i] = arr[i-1] + sign*(double ((1.0)/i));
			sign = - sign;
			//cout<<arr[i]<<endl;
		}
	}
}

int main(){
	int m , n;
	double res;
	Sum();
	cin>>m;
	for(int i = 0 ; i < m ; i++){
		cin>>n;
		res = arr[n];
		printf("%.2f\n",res);
	}
	return 0;
}
