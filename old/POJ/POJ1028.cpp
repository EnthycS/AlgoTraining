#include<stack>
#include<iostream>
#include<string>
using namespace std;


stack<string> FORWARD;
stack<string> BACKWARD;
string CurrentPage = "http://www.acm.org/";
string Command = "";
int main(){
	while(cin>>Command){
		if(Command == "QUIT"){
			break;
		}else if(Command == "BACK"){
			if(BACKWARD.empty()){
				cout<<"Ignored"<<endl;
			}else{
				FORWARD.push(CurrentPage);
				CurrentPage = BACKWARD.top();
				BACKWARD.pop();
				cout<<CurrentPage<<endl;
			}
		}else if(Command == "FORWARD"){
			if(FORWARD.empty()){
				cout<<"Ignored"<<endl;
			}else{
				BACKWARD.push(CurrentPage);
				CurrentPage = FORWARD.top();
				FORWARD.pop();
				cout<<CurrentPage<<endl;
			}
			
		}else if(Command == "VISIT"){
			string newPage;
			cin>>newPage;
			while(!FORWARD.empty()){
				FORWARD.pop();
			}
			BACKWARD.push(CurrentPage);
			CurrentPage = newPage;
			cout<<CurrentPage<<endl;
		}
	}
	return 0;
}
