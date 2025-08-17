#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<cstring>
#include<string.h>

using namespace std;

int compare(char a, char b){
	if(tolower(a) != tolower(b)){
		return tolower(a) < tolower(b);
	}else{
		return a < b;
	}
}

void solve(){
	char ch[20];
	scanf("%s",ch);
	sort(ch,ch+strlen(ch),compare);
	do{
		printf("%s\n",ch);
	}while(next_permutation(ch,ch+strlen(ch),compare));
}

int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
