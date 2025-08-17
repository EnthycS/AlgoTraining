#include<bits/stdc++.h>
using namespace std;

int getSum(int a){
	int res = 0;
	for(int i = 1 ; i <= (a/2) ; i++){
		if( (a % i) == 0){
			res += i;
		}
	}
	
	return res;
}

int main(){
	int n;
	cin>>n;
	while(n--){
		int A,B;
		cin>>A>>B;
		int resA = getSum(A);
		int resB = getSum(B);
		if(resA == B && resB == A){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}

