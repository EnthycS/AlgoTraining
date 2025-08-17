#include<bits/stdc++.h>
using namespace std;


double a[21] = {1,1,2,6};
double b[21] = {0,0,1,2};

void initialize(){
	for(int i = 4 ; i < 21 ; i++){
		b[i] = (i-1)*(b[i-1] + b[i-2]);
		a[i] = i * a[i-1];
		//cout<<b[i]<<"/"<<a[i]<<endl;
	}
	
}
int main(){
	initialize();
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		printf("%.2lf%%\n",b[m]/a[m]*100);
	}
	
	return 0;
}
