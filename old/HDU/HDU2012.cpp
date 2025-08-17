#include<bits/stdc++.h>
using namespace std;

bool predicate(int x){
	for(int i = 2 ; i <= sqrt(x) ; i++){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

bool res[10000];
void AllNums(){
	for(int i = 30 ; i < 10000 ; i++){
		if(predicate(i)){
			res[i] = true;
		}else{
			res[i] = false;
		}
	}
}
int main(){
	AllNums();
	int x,y;
	while(cin>>x>>y){
		if(x == 0 && y == 0){
			break;
		}else{
			bool flag = true;
			for(int i = x ; i <= y ; i++){
				int temp = i*i + i + 41;
				if(res[temp] == false){
					cout<<"Sorry"<<endl;
					flag = false;
					break;
				}
			}
			if(flag == true){
				cout<<"OK"<<endl;
			}else{
				
			}
		}
	}
	return 0;
} 
