#include<bits/stdc++.h>

using namespace std;

int T;
int a[7];
string s,ans;
int main(){
	cin>>T;
	for(int i = 0 ; i < T; i++){
		for(int j = 0 ; j < 7 ; j++){
			scanf("%d",&a[j]);
		}
		getchar();
		
		queue<string> q1[a[0]];
		deque<int> qr;
		queue<int> qb;
		
		for(int j = 0 ; j < a[0] ; j++){
			while(getline(cin,s) && s != "end"){
				q1[j].push(s);
			}
			qr.push_back(j);
		}
		
		if(i != 0)puts("");
		map<string,string> vmp;
		bool isLock = false;
		
		while(!qr.empty()){
			int t = 0;
			int k = qr.front();
			qr.pop_front();
			bool isBlock = false;
			while(t < a[6] && !q1[k].empty()){
				s = q1[k].front();
				int j = s.find('=');
				if(j != string::npos){
					vmp[s.substr(0,j-1)] = s.substr(j+2);
					t += a[1];
				}else{
					j = s.find(' ');
					if(j != string::npos){
						ans = "0";
						if(vmp[s.substr(j+1)] != "") ans = vmp[s.substr(j+1)];
						printf("%d: %s\n", k+1, ans.c_str()); 
						t += a[2];
					}else{
						if(s[0] == 'l'){
							if(!isLock){
								isLock = true;
								t += a[3];
							}else{
								qb.push(k);
								isBlock = true;
								break;
							}
							
						}else if(s[0] == 'u'){
							isLock = false;
							if(!qb.empty()){
								qr.push_front(qb.front());
								qb.pop();
							}
							t += a[4];
						}
					}
					 
				}
				
				q1[k].pop();
			} 
			if (!q1[k].empty() && !isBlock) qr.push_back(k);
		}
		
		
		
	}
	return 0;
}
