#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;
typedef long long ll;
int stepx[4] = { -1,1,0,0 };
int stepy[4] = { 0,0,-1,1 };
struct node {
	int p[4], vis;
	bool check(int v) { //查重
		for (int i : p)
			if (i == v)
				return 1;
		return 0;
	}
	int hash() {
		int a[4];
		memcpy(a, p, sizeof(a));
		sort(a, a + 4);
		int res = 0;
		for (int i : a)
			res = res * 100 + i;
		return res;
	}
};

unordered_set<int> st[2]; //存hashc
queue<node> q[2];

void clear() {
	for (int i = 0; i < 2; i++) {
		queue<node>c;
		swap(q[i], c);
		st[i].clear();
	}
}
bool ans(int i, int hash) {//队列下标和待查hash
	if (st[i].find(hash) != st[i].end()) //相遇
		return true;
	return false;
}
bool dbfs() {
	while (!q[0].empty() || !q[1].empty()) {
		for (int i = 0; i < 2; ++i) { //2个队列
			if (!q[i].empty()) {
				node cur = q[i].front(); q[i].pop();
				cur.vis++;
				for (int j = 0; j < 4; ++j) { //4个点
					int x = cur.p[j] / 10, y = cur.p[j] % 10;
					for (int k = 0; k < 4; ++k) { //4个方向
						int nx = x + stepx[k], ny = y + stepy[k];
						if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && cur.check(nx * 10 + ny))
							nx += stepx[k], ny += stepy[k];
						if (nx >= 1 && nx <= 8 && ny >= 1 && ny <= 8 && cur.vis <= 4 && //小于四步
							!cur.check(nx * 10 + ny)) {
							cur.p[j] = nx * 10 + ny;
							if (st[i].find(cur.hash()) == st[i].end()) {
								if (ans(!i, cur.hash()))return true;
								q[i].push(cur), st[i].insert(cur.hash()); //入队
							}
						}
					}
					cur.p[j] = x * 10 + y; //回溯
				}
			}
		}
	}
	return false;
}
int main() {
	while (true) {
		clear();
		node t;
		int a;
		t.vis = 0;
		for (int k = 0; k < 2; ++k) {
			for (int i = 0; i < 4; ++i) {
				t.p[i] = 0;
				for (int j = 0; j < 2; ++j) {
					if (scanf("%d", &a) == EOF)exit(0);
					t.p[i] = t.p[i] * 10 + a;
				}
			}
			q[k].push(t);
			st[k].insert(t.hash());
		}
		if (ans(0, q[1].front().hash()) || dbfs())
			printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
