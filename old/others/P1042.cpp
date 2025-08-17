#include <bits/stdc++.h>

using namespace std;

const int N = 25 * 2501 + 15;
char s[N];
int cnt = 0;
void showResult(int n){//n代表11分制或21分制 
	int win = 0;
	int lose = 0;
	for(int i = 0 ; i < cnt ; i++){
		if( (win >= n || lose >= n) && abs(win - lose) >= 2 ){
			cout<<win<<":"<<lose<<endl;
			win = 0;
			lose = 0;
		}
		
		if(s[i] == 'W')win++;
		else if(s[i] == 'L')lose++;
	}
	
	if(win > 0 || lose > 0){
		cout<<win<<":"<<lose<<endl;
	}
	
	//if( (win >= n || lose >= n) && win != lose ){
	//	cout<<0<<":"<<0<<endl;
	//}
}

int main(){
	
	char ch;
	while(cin>>ch && ch != 'E'){
		if(ch == 'W' || ch == 'L')s[cnt++] = ch;
	}
	
	if(ch == 'E' && cnt == 0) {
		cout << "0:0\n\n0:0";
	}
	showResult(11);
	cout<<endl;
	showResult(21);
	return 0;
}
