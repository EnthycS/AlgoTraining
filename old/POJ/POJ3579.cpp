#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
int N;
const int MAX = 100010;
int a[MAX];

bool check(int val){
	int cnt = 0 ;
	int m = N*(N-1)/4;
	for(int i = 0 ; i < N ; i++){
		cnt += N - (lower_bound(a,a+N,a[i]+val) - a) ;
	}
	return cnt > m;
}
int main(){
	while(cin>>N){
		int ans;
		for(int i = 0 ; i < N ; i++){
			int t;
			scanf("%d",&t);
			a[i] = t;
		}
		
		int l = 0;
		sort(a,a+N);
		int r = a[N-1] - a[0];
		
		while(l <= r){
			int mid = (l+r)>>1;
			if(check(mid)){
				ans = mid;
				l = mid + 1;
			}else{
				r = mid - 1;
			}
		}
		
		cout<<ans<<endl;
	}
}
