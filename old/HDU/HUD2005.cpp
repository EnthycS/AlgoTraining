#include<bits/stdc++.h>

using namespace std;

int days[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
bool predicate(int year){
	if(year%400 == 0 || (year%4 == 0 && year % 100 != 0)){
		return true;
	}
	else{
		return false;
	}
}
int main(){
	int year,month,day;
	char t;
	while(cin>>year>>t>>month>>t>>day){
		//cout<<predicate(year)<<endl;
		//cout<<year<<endl;
		if(predicate(year)){
			days[2] = 29;
		}else{
			days[2] = 28;
		}
		
		int ans = 0;
		for(int i = 1 ; i < month ; i++){
			ans += days[i];
		}
		ans += day;
		cout<<ans<<endl;
	}
	return 0;
}
