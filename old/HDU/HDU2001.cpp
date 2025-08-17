#include<bits/stdc++.h>

using namespace std;

int main(){
	double x1,y1,x2,y2;
	double res = 0.0;
	while(cin>>x1>>y1>>x2>>y2){
		res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
		printf("%.2f\n",res);
	}
	return 0;
}
