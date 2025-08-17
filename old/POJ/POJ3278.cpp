#include<bits/stdc++.h>

using namespace std;

int line[1000001];
struct node{
	int x;
	int minute;
};
vector<node> res;
#define CHECK(x)(x <= 100000 && x>=0)
void BFS(int x , int y,int m){
	
	queue<node> q;
	node start,next;
	start.x = x;
	start.minute = m;
	
	q.push(start);
	while(!q.empty()){
		start = q.front();
		q.pop();
		next.x = start.x * 2;
		next.minute = start.minute+1;
		if(next.x == y)res.push_back(next);
		else
			if(CHECK(next.x) && line[next.x] == 0){q.push(next); line[next.x] = 1;}
			
		
		next.x = start.x - 1;
		next.minute = start.minute+1;
		if(next.x == y)res.push_back(next);
		else
			if(CHECK(next.x)&& line[next.x] == 0){q.push(next); line[next.x] = 1;}
		
		next.x = start.x + 1;
		next.minute = start.minute+1;
		if(next.x == y)res.push_back(next);
		else
			if(CHECK(next.x)&& line[next.x] == 0){q.push(next); line[next.x] = 1;}
	}
}

int main(){
	
	int n , k;
	cin>>n>>k;
	line[n] = 1;
	line[k] = 2;
	
	if (n >= k) {
        cout << n - k << endl;
        return 0;
    }
    BFS(n,k,0);
    int min = 0;
    for(int i = 1 ; i < res.size() ; i++){
    	if(res[min].minute > res[i].minute){
    		min = i;
		}
	}
	cout<<res[min].minute;
	return 0;
}
