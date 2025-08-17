#include<bits/stdc++.h>

using namespace std;
const int N = 1005;

int n,m;
vector<int> G[N];
bool vis[N];

struct node{
	int x;
	int step;
};

int bfs(int s){
	memset(vis,0,sizeof(vis));
	queue<node> q;
	node start ;
	start.x = s;
	start.step = 0;
	q.push(start);
	vis[s] = 1;
	int ans = 0;
	while(!q.empty()){
		node now = q.front();
		q.pop();
		
		ans = max(ans,now.step);
		for(int i = 0 ; i < G[now.x].size(); i++){
			int y = G[now.x][i];
			if(!vis[y]){
				node next;
				next.x = y;
				next.step = now.step + 1;
				q.push(next);
				vis[y] = 1;
				ans = max(ans,next.step);
			}
		}
	}
	
	return ans;
}
int main(){
	while(cin>>n){
		if(n == 0)break;
		int cnt = 0;
		string s;
		map<string,int> mp;
		for(int i = 1; i <= n ; i++){
			cin>>s;
			mp[s] = ++cnt;
		}
		cin>>m;
		memset(vis,1,sizeof(vis));
		for(int i = 1; i <= n ; i++){
			G[i].clear();
		}
		for(int i = 0 ; i < m ; i++){
			string a,b;
			cin>>a>>b;
			int x = mp[a];
			int y = mp[b];
			G[x].push_back(y);
			G[y].push_back(x);
			vis[x] = vis[y] = 0;
		}
		
		bool flag = false;
		for(int i = 1 ; i <= n ; i++){
			if(vis[i]){
				cout<<"-1"<<endl;
				flag = true;
				break;
			}
		}
		if(flag)continue;
		
		int ans = 0;
		for(int i = 1 ; i <= n ; i++){
			ans = max(ans,bfs(i));
		}
		cout<<ans<<endl;
		
	}
	return 0;
}
