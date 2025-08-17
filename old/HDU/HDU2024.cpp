#include<bits/stdc++.h>
using namespace std;

bool predicate(char s[]){

	bool flag = true;
	
	for(int i = 0 ; s[i] ; i++){
		if( (i == 0 && (s[i] >= '0' && s[i] <= '9') ) ||
			(! ((s[i] >= '0' && s[i] <= '9') || (s[i] == '_') || (s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') )  )
		)
		{
			flag = false;
			break;
		}
	}
	
	return flag;
}

int main(){
	int n;
	cin>>n;
	char s[50];
	for(int i = 0 ; i < n ; i++){
		fflush(stdin);
		gets(s);
		if(predicate(s)){
			cout<<"yes"<<endl;
		}else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
