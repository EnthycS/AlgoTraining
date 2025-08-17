#include<bits/stdc++.h>

using namespace std;

int main(){
	int score;
	while(cin>>score){
		if(score > 100|| score < 0){
			cout<<"Score is error!"<<endl;
		}else{
			if(score >= 90 &&score <= 100){
				cout<<"A"<<endl;
			}else if(score >= 80 &&score <= 89){
				cout<<"B"<<endl;
			}else if(score >= 70 &&score <= 79){
				cout<<"C"<<endl;
			}else if(score >= 60 &&score <= 69){
				cout<<"D"<<endl;
			}else{
				cout<<"E"<<endl;
			}
		}
	}
	return 0;
}
