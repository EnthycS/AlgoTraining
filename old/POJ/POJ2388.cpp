#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
const int MAX = 10010;
int main(){
	int n;
	int a[MAX];
	while(cin>>n){
		for(int i = 0 ; i < n ; i++){
			cin>>a[i];
		}
		
		int mid = n>>1;
		nth_element(a,a+mid,a+n);
		cout<<a[mid]<<endl;
	}
	return 0;
}
