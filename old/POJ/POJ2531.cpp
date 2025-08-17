#include<bits/stdc++.h>

using namespace std;
int n;
const int MAX = 25;
int matrix[MAX][MAX];

int res ;

int A[MAX];

void DFS(int x, int ans){
	if(x == n+1){
		res = max(res,ans);
		return;
	}
	
	int ans2 = ans;
	DFS(x+1,ans);
	A[x] = 1;
	for(int  i=1;i<x;i++)
           if(A[i]==1)ans2-=matrix[x][i];
    for(int i=1;i<=n;i++)
          if(A[i]==0)ans2+=matrix[x][i];
    if(ans2>=ans){DFS(x+1,ans2);}
    A[x]=0;
     

}

int main(){
	cin>>n;
	for(int i = 1 ; i <= n ; i++ ){
		for(int j = 1 ; j <= n ; j ++){
			cin>>matrix[i][j];
		}
	}
	memset(A,0,sizeof(A));
    DFS(1,0);
    
    cout<<res<<endl;
	
	return 0;
}
