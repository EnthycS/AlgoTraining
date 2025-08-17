#include<bits/stdc++.h>

using namespace std;

int main(){
	double r;
	while(cin>>r){
		if(r < 0){
			r = -r;
		}
		printf("%.2f\n",r);
	}
	return 0;
}
