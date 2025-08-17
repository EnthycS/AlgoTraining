#include<bits/stdc++.h>

#define Mx 10086
using namespace std;


int match[Mx];	//match[i]表示第i个女生当前匹配的男生编号，0表示没有
vector<int>boys[Mx];//记录每个男生可能匹配到的女生
int vis[Mx];	//记录在这一次选择中被访问过的结点
int bn, gn, n;

/*dfs==true的条件是这个兄弟找到了匹配，
而且不会使得其他已经找到匹配的兄弟失去匹配，包含了对match的更新*/
bool dfs(int x) {
	//细节转int
	for (int i = 0; i < (int)boys[x].size(); i++) {
		int g = boys[x][i];
		if (vis[g] == 0) {
			vis[g] = 1;
			if (match[g] == 0 || dfs(match[g])) {
				match[g] = x;
				return true;
			}
		}
	}
	return false;
}


int main() {
	while (scanf("%d", &n) && n && scanf("%d %d", &bn, &gn)) {
		memset(match, 0, sizeof(match));
		for (int i = 0; i < gn+1; i++) {
			boys[i].clear();
		}
		for (int i = 0; i < n; i++) {
			int a, b;	//a为男生编号，b为女生编号
			scanf("%d %d", &a, &b);
			boys[a].push_back(b);
		}
		int ans = 0;
		//选择男生部，作为起始的未匹配点进行遍历
		for (int i = 1; i <= bn; i++) {
			memset(vis, 0, sizeof(vis));
			if (dfs(i)) {
				ans++;
			}
		}
		printf("%d\n", ans);

	}
	return 0;
}

