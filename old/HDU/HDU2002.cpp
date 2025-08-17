#include<bits/stdc++.h>

using namespace std;
const double PI = 3.1415927;

int main(){
	double r,res;
	while(cin>>r){
		res = (4*(PI*r*r*r)) / 3;
		printf("%.3f\n",res);
	}
	return 0;
}
