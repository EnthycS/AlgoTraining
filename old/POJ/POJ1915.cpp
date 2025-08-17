#include<stack>
#include<iostream>
#include<string>
#include<queue>
#include<cstring>
using namespace std;
const int MAX = 305;
bool visited[MAX][MAX] = {false};
char board[MAX][MAX] = {'#'};


int dx[8]={-2,-2,-1,-1,1,1,2,2};
int dy[8]={1,-1,2,-2,2,-2,1,-1};

bool CHECK(int x,int y,int len){
	if(x >= 0 && y >= 0 && x < len && y < len && !visited[x][y]){
		return true;
	}else {
		return false;
	}
}
struct node{
	int x;
	int y;
	int step;
};

void solve(){
	int len;
	int startX,startY;
	int targetX,targetY;
	cin>>len;
	cin>>startX>>startY;
	cin>>targetX>>targetY;
	struct node d;
	struct node t;
	d.x = startX;
	d.y = startY;
	d.step = 0;
	t.x = targetX;
	t.y = targetY;
	
	memset(visited,false,sizeof(visited));
	queue<node> q;
	q.push(d);
	visited[startX][startY] = true;
	board[startX][startY] = 'S';
	board[targetX][targetY] = 'T';
	
	
	int tx,ty;
	if(startX == targetX && startY == targetY){
		cout<<0<<endl;
	}else{
		bool flag = false;
		while(!q.empty()){
			if(flag == true)break;
			struct node now , next;
			now = q.front();
			q.pop();
			int x = now.x;
			int y = now.y;
			int step = now.step;
			
			for(int i = 0 ; i < 8 ; i++){
				tx = x + dx[i];
				ty = y + dy[i];
				if( tx == targetX && ty == targetY){
					cout<<step+1<<endl;
					flag = true;
					break;
				}
				if(CHECK(tx,ty,len)){
					next.x = tx;
					next.y = ty;
					next.step = step+1;
					q.push(next);
					visited[tx][ty] = true;
				}
			}
		}
	}
}

int main(){
	int n;
	cin>>n;
	while(n--){
		solve();
	}
	return 0;
}
