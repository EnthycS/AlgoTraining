#include <cstdio>
#include <string>
#include <cstring>
#include <queue> 
#include <iostream>


using namespace std;


struct node {
	int a, b, step;
	string opt;
	node(int a, int b, string opt, int step): a(a), b(b), opt(opt), step(step){}
};

int a,b,c;

const int MAX = 101;
bool visited[MAX][MAX];
string bfs(){
	queue<node> q;
	q.push(node(0, 0, "", 0));
	visited[0][0] = true;
	while(!q.empty()){
		node t = q.front();
		q.pop();
		if(t.a == c || t.b == c){
			cout<<t.step<<endl;
			return t.opt;
		}
		
		if(!visited[a][t.b]){
			visited[a][t.b] = true;
			q.push(node(a,t.b,t.opt+"FILL(1)\n",t.step+1));
		}
		
		if(!visited[t.a][b]){
			visited[t.a][b] = true;
			q.push(node(t.a,b,t.opt+"FILL(2)\n",t.step+1));
		}
		
		if(t.a!= 0 && !visited[0][t.b]){
			visited[0][t.b] = true;
			q.push(node(0,t.b,t.opt+"DROP(1)\n",t.step+1));
		}
		
		if(t.b!= 0 && !visited[t.a][0]){
			visited[t.a][0] = true;
			q.push(node(t.a,0,t.opt+"DROP(2)\n",t.step+1));
		}
		
		//第三种操作 将i to j 
		if (t.a != 0 && t.b != b) {
			int cha = b - t.b;
			if (cha >= t.a) {
				//将a全部导入b
				if (!visited[0][t.b + t.a]) {
					visited[0][t.b + t.a] = true;
					q.push(node(0, t.b + t.a, t.opt + "POUR(1,2)\n", t.step + 1));
				} 
			} else {
				if (!visited[t.a - cha][b]) {
					visited[t.a - cha][b] = true;
					q.push(node(t.a - cha, b, t.opt + "POUR(1,2)\n", t.step + 1));
				}
			}
		} 
		if (t.b != 0 && t.a != a) {
			int cha = a - t.a;
			if (cha >= t.b) {
				// 将b全部导入a
				if (!visited[t.a + t.b][0]) {
					visited[t.a + t.b][0] = true;
					q.push(node(t.a + t.b, 0, t.opt + "POUR(2,1)\n", t.step + 1));
				} 
			} else {
				if (!visited[a][t.b - cha]) {
					visited[a][t.b - cha] = true;
					q.push(node(a, t.b - cha, t.opt + "POUR(2,1)\n", t.step + 1));
				}
			}

	}
	
	
	}
	return "impossible";
}

int main(){
	
	cin>>a>>b>>c;
	cout<<bfs();
	return 0;
}
