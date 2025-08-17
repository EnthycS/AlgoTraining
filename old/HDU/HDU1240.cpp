#include<bits/stdc++.h>

using namespace std;

struct node{
	int x,y,z;
	int step;
}; 

int dir[6][3] = {{-1,0,0},{1,0,0},{0,-1,0},{0,1,0},{0,0,-1},{0,0,1}};

bool vis[100][100][100];
char a[100][100][100];
int n;

bool CHECK(int x,int y,int z){
	return x >= 0 && x< n && y >= 0 && y < n && z >= 0 && z < n;
}

void BFS(int dx,int dy,int dz,int tx,int ty,int tz){
	node origin;
	origin.x = dx;
	origin.y = dy;
	origin.z = dz;
	origin.step = 0;
	
	queue<node> q;
	q.push(origin);
	
	while(!q.empty()){
		node now = q.front();
		q.pop();
		node next;
		if (now.x == tx && now.y == ty && now.z == tz) {
			cout << n<<" "<<now.step << endl;
			return;
		}
		
		for(int i = 0 ; i < 6 ; i++){
			next.x = now.x + dir[i][0];
			next.y = now.y + dir[i][1];
			next.z = now.z + dir[i][2];
			
			if (CHECK(next.x,next.y,next.z)&&!vis[next.x][next.y][next.z] && a[next.x][next.y][next.z] != 'X') {
				next.step = now.step + 1;
				q.push(next);
				vis[next.x][next.y][next.z] = true;
			}
		}
	}
	
	cout << "NO ROUTE" << endl;
}
int main(){
	int dx,dy,dz,tx,ty,tz;
	string s1,s2;
	while(cin>>s1>>n){
		memset(vis,false,sizeof(vis));
		for(int k = 0 ; k < n ; k++){
			for(int i = 0 ; i < n ; i++){
				for(int j = 0 ; j < n ; j++){
					cin>>a[i][j][k];
				}
			}
		}
		cin>>dx>>dy>>dz;
		cin>>tx>>ty>>tz;
		cin>>s2;
		BFS(dx,dy,dz,tx,ty,tz);
	}
	return 0;
}
