#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	while(n--){
		int m;
		cin>>m;
		string name;
		double c,s;
		double totalC = 0,totalS = 0;
		bool flag = true;
		for(int i = 0 ; i < m ; i++){
			cin>>name>>c>>s;
			if(s < 60){
				
				flag = false;
				
			}else{
				totalC += c;
				totalS += c*s;
			}
		}
		
		if(flag){
			printf("%.2lf\n",(totalS/totalC));
		}else{
			cout<<"Sorry!"<<endl;
		}
		if(n == 0){
			
		}else{
			cout<<endl;
		}
	}
	return 0;
}
