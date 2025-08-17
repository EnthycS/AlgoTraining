#include<bits/stdc++.h>
using namespace std;

int a[35];
void SumOfPeaches(){
	a[1] = 1;
	for(int i = 2 ; i<= 34 ; i++){
		a[i] = 2*a[i-1] + 2;
	}
}
int main(){
	int n;
	SumOfPeaches();
	while(cin>>n){
		cout<<a[n]<<endl;
	}
	return 0;
}
