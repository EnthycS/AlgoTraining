#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

int main() {
    int n;
    while (cin >> n && n != 0) {
        queue< pair<string, int> > q;
        vector<bool> visited(n, false);
        q.push({"1", 1 % n});
        visited[1 % n] = true;
        string ans = "";
        while (!q.empty()) {
            // 显式指定current的类型为pair<string, int>
            pair<string, int> current = q.front();
            q.pop();
            string s = current.first;
            int r = current.second;
            if (r == 0) {
                ans = s;
                break;
            }
            if (s.size() < 100) {
                // 生成s+"0"
                string s0 = s + "0";
                int r0 = (r * 10 + 0) % n;
                if (r0 == 0) {
                    ans = s0;
                    break;
                }
                if (!visited[r0]) {
                    visited[r0] = true;
                    q.push({s0, r0});
                }
                // 生成s+"1"
                string s1 = s + "1";
                int r1 = (r * 10 + 1) % n;
                if (r1 == 0) {
                    ans = s1;
                    break;
                }
                if (!visited[r1]) {
                    visited[r1] = true;
                    q.push({s1, r1});
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
