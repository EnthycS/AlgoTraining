#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,m;
	while(~scanf("%d%d",&n,&m)){
		if(n == 0 && m == 0){
			break;
		}
		int k = sqrt((double)(m)*2);
		for(int i = k ; i > 0 ; i--){
			int a1 = (m*2/i - i + 1)/2;
			if ((i*a1 + i*(i-1)/2) == m){
				if(a1 > 0) printf("[%d,%d]\n",a1,a1+i-1);
			}
		}
	}
	return 0;
}
