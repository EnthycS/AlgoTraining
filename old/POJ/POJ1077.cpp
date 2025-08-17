#include<iostream>
#include<queue>
#include<cstring>
#include<stdio.h>

using namespace std;
const int Len = 362880;//一共有9！种全排列

struct node{
    int state[9];
    int count;//记录步数
    char d[100];//记录每一步的方向
};
int vis[Len] = {0};//0表示第Len种情况还没出现过
int start[9];
int goal[9] = {1,2,3,4,5,6,7,8,0};
int dir[4][2] = {//4个方向
    {0,-1},//up
    {1,0},//right
    {0,1},//down
    {-1,0}//left
    
   
};
long int factory[] = {1,1,2,6,24,120,720,5040,40320,362880};//康托展开常用阶乘

bool Cantor(int str[],int n){
	long result = 0;
	for(int i = 0 ; i < n ; i++){
		int count = 0 ;
		for(int j = i + 1 ; j < n ; j++){
			if(str[i] > str[j]){
				count++;
			}
			
		}
		result += count * factory[n-i-1];
	}
	if(!vis[result]){
		vis[result] = 1;
		return 1;
	}
	else
		return 0;
}

int bfs(){
	node head;
	queue<node> q;
	memcpy(head.state,start,sizeof(head.state));
	head.count = 0 ;
	Cantor(head.state,9);
	q.push(head);
	
	while(!q.empty()){
		head = q.front();
		q.pop();
		int z;
		for(z = 0 ; z < 9 ; z++){
			if(head.state[z] == 0){
				break;
			}
		}
		
		int x,y;
		x = z%3;
		y = z/3;
		for(int i = 0 ; i < 4 ; i++){
			int newx,newy;
			newx = x + dir[i][0];
			newy = y + dir[i][1];
			int nz = newx + 3*newy;
			
			if(newx>= 0 && newx < 3 && newy>=0 && newy < 3){
				node newnode;
				memcpy(&newnode,&head,sizeof(node));
				swap(newnode.state[z],newnode.state[nz]);
				
				if(i == 0){newnode.d[newnode.count] = 'u';newnode.count++; }//记录每一步
                if(i == 1){newnode.d[newnode.count] = 'r';newnode.count++; }
                if(i == 2){newnode.d[newnode.count] = 'd';newnode.count++; }
                if(i == 3){newnode.d[newnode.count] = 'l';newnode.count++; }
                
                if(memcmp(newnode.state,goal,sizeof(goal)) == 0){//找到了
                    for(int j = 0; j<newnode.count; j++){
                        printf("%c",newnode.d[j]);
                    }
                    return 1;
                }
                if(Cantor(newnode.state,9)){//不重复
                    q.push(newnode);
                }

			}
		}
	}
	
	return -1;
}

int main(){
	char s[100];
    int k = 0;
    gets(s);
    char *p;
    for( p = s; *p != '\0'; p++){
        if( *p != ' '){
            if(*p == 'x')
                start[k++] = 0;//把x转化为0
            else
                start[k++] = *p -'0';
        }
    }
    
    int num = bfs();
    if(num == -1){
    	cout<<"unsolvable"<<endl;
	}
	
	cin.get();
	cin.get();

	return 0;
} 
