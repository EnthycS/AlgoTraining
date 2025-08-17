#include<bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
	if(b == 0){
		return a;
	}else{
		return gcd(b,a % b);
	}
}

int lcm(int a,int b){
	if( a > b){
		return b*(a/gcd(a,b));
	}else{
		return b*(a/gcd(b,a));
	}
}

int main(){
	int n , a ,b;
	while(~scanf("%d",&n)){
		scanf("%d",&a);
		for(int i = 1 ; i < n ; i++){
			scanf("%d",&b);
			a = lcm(a,b);
		}
		
		printf("%d\n",a);
	}
	return 0;
}
