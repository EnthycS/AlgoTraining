#include<bits/stdc++.h>

using namespace std;
struct Job{
	int pos;
	int prio;
}job;


int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		int time = 0;
		queue<Job> q;
		map<int,int> mp;//map(优先级,个数)
		
		for(int i = 0 ; i < n ; i++){
			int t;
			cin>>t;
			job.prio = t;
			job.pos = i;
			q.push(job);
			mp[job.prio]++;
		}
		
		while(!q.empty()){
			if(q.front().prio < mp.rbegin()->first){
				q.push(q.front());
				q.pop();
			}else{
				if(q.front().pos == m){
					break;
				}else{
					time++;
					if(mp[q.front().prio] == 1){
						mp.erase(q.front().prio);
					}else{
						mp[q.front().prio]--;
					}
					
					q.pop();
					
				}
			}
		}
		
		cout<<time+1<<endl;
	}
	return 0;
}
