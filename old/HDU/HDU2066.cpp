#include <cstdio>
#include <queue>
#include <cstring>
#include <iostream>
using namespace std;
const int N = 2005, INF = 0x3f3f3f3f;
struct E {
	int v, w, next;
} e[N * 100];
struct Node {
	int v, d;
	Node(int v, int d):v(v), d(d) {}
	bool operator < (const Node &w)const {
		return d > w.d;
	}
};
int m, S, D, len, head[N], d[N];
bool vis[N];
void add(int u, int v, int w) {
	e[len].v = v;
	e[len].next = head[u];
	e[len].w = w;
	head[u] = len++;
}
void djkstra() {
	int u;
	memset(d, 0x3f, sizeof(d));
	memset(vis, false, sizeof(vis));
	priority_queue<Node> q;
	q.push(Node(0, 0));
	d[0] = 0;
	while (!q.empty()) {
		u = q.top().v;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int j = head[u]; j != -1; j = e[j].next) {
			int v = e[j].v;
			int w = e[j].w;
			if (!vis[v] && d[v] > d[u] + w) {			
				d[v] = d[u] + w;
				q.push(Node(v, d[v]));
			}
		}
	}
}

int main() {
	while (scanf("%d%d%d", &m, &S, &D) != EOF) {
		len = 0;
		memset(head, -1, sizeof(head));
		int u, v, w;
		for (int i = 1; i <= m; i++) {
			scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		}
		//????????????????
		for (int i = 1; i <= S; i++) {
			scanf("%d", &v);
			add(0, v, 0);
			add(v, 0, 0);
		} 
		djkstra();
		int ans = 0x7f7f7f7f;
		for (int i = 1; i <= D; i++) {
			scanf("%d", &v);
			ans = min(ans, d[v]);
		}
		printf("%d\n", ans);
	}
	return 0;
}

