#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 10000;
bool is_prime[MAX];

// 预处理埃拉托斯特尼筛法生成质数表
void sieve() {
    memset(is_prime, true, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i * i < MAX; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < MAX; j += i) {
                is_prime[j] = false;
            }
        }
    }
}

vector<int> generate_next(int num){
	vector<int> res;
    int a = num / 1000;
    int b = (num % 1000) / 100;
    int c = (num % 100) / 10;
    int d = num % 10;
    
    for (int new_a = 1; new_a <= 9; ++new_a) {
        if (new_a == a) continue;
        int new_num = new_a * 1000 + b * 100 + c * 10 + d;
        if (is_prime[new_num]) {
            res.push_back(new_num);
        }
    }
    
    for(int new_b = 0; new_b <= 9;++new_b){
    	if(new_b == b)continue;
    	int new_num = a * 1000 + new_b * 100 + c * 10 + d;
    	if(is_prime[new_num]){
    		res.push_back(new_num);
		}
	}
	
	for(int new_c = 0; new_c <= 9;++new_c){
    	if(new_c == c)continue;
    	int new_num = a * 1000 + b * 100 + new_c * 10 + d;
    	if(is_prime[new_num]){
    		res.push_back(new_num);
		}
	}
	
	for(int new_d = 0; new_d <= 9;++new_d){
    	if(new_d == d)continue;
    	int new_num = a * 1000 + b * 100 + c * 10 + new_d;
    	if(is_prime[new_num]){
    		res.push_back(new_num);
		}
	}
	
	return res;

}

int bfs(int start,int end){
	if(start == end)return 0;
	
	bool visited[MAX];
    memset(visited, false, sizeof(visited));
    queue<int> q;
    q.push(start);
    visited[start] = true;
    
    int steps = 0;
    while(!q.empty()){
    	int size = q.size();
    	steps++;
    	for(int i = 0 ; i < size ; i++){
    		int current = q.front();
    		q.pop();
    		
    		vector<int> nexts = generate_next(current);
    		for(int j = 0 ; j < nexts.size() ; j++){
    			int next = nexts[j];
    			if(next == end)return steps;
    			if(!visited[next]){
    				visited[next] = true;
    				q.push(next);
				}
			}
		}
	}
}

int main(){
	sieve();
	int n;
	cin>>n;
	for(int i = 0 ; i < n ;  i++){
		int steps = 0;
		int a ,b;
		cin>>a>>b;
		steps = bfs(a,b);
		if (steps == -1) {
            cout << "Impossible" << endl;
        } else {
            cout << steps << endl;
        }
	}
	return 0;
}

