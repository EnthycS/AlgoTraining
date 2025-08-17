#include<bits/stdc++.h>

#define Mx 10086
using namespace std;


int match[Mx];	//match[i]��ʾ��i��Ů����ǰƥ���������ţ�0��ʾû��
vector<int>boys[Mx];//��¼ÿ����������ƥ�䵽��Ů��
int vis[Mx];	//��¼����һ��ѡ���б����ʹ��Ľ��
int bn, gn, n;

/*dfs==true������������ֵ��ҵ���ƥ�䣬
���Ҳ���ʹ�������Ѿ��ҵ�ƥ����ֵ�ʧȥƥ�䣬�����˶�match�ĸ���*/
bool dfs(int x) {
	//ϸ��תint
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
			int a, b;	//aΪ������ţ�bΪŮ�����
			scanf("%d %d", &a, &b);
			boys[a].push_back(b);
		}
		int ans = 0;
		//ѡ������������Ϊ��ʼ��δƥ�����б���
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

