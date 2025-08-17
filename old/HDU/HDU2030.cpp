#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d",&n);
	
	getchar();
	while(n--){
		char ch;
		int cnt = 0;
		for(;;){
			if((ch = getchar()) == '\n')break;
			if(ch < 0)cnt++;
		}
		cout<<cnt/2<<endl;
	}
	return 0;
}
