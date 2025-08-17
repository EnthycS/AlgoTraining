#include<bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	int AH,AM,AS,BH,BM,BS;
	int c = 0;
	for(int i = 0 ; i < n ; i++){
		
		cin>>AH>>AM>>AS>>BH>>BM>>BS;
		int CH,CM,CS;
		c = 0;
		if(AS + BS >= 60){
			c = 1;
			CS = ( AS + BS ) % 60;
		}else{
			CS = AS + BS;
		}
		
		if( AM + BM + c >= 60){
			CM = (AM + BM + c) % 60;
			c = 1;
			
		}else{
			CM = (AM + BM + c);
			c = 0;
		}
		
		CH =  AH + BH + c;
		
		cout<<CH<<" "<<CM<<" "<<CS<<endl;
		
	}
	return 0;
}
