#include<bits/stdc++.h>
using namespace std;
int n, m, op, a, b, num=0;
int main() {
    while (scanf("%d %d", &n, &m) == 2) {
        list<int> l(n); // �洢1-n
        vector<list<int>::iterator> pos(n+1); // pos[i]��ʾ����i��list�е�ָ��
        int idx=1, inv=0;
        for (auto p=l.begin(); p != l.end(); p++, idx++) { // ��ʼ��
            *p = idx;
            pos[idx] = p;
        }
        for (int i = 0; i < m; i ++) { // m������
            scanf("%d", &op);
            if (op != 4) scanf("%d %d", &a, &b);
            if (op == 4) inv = !inv; // ��ת���
            else if (op == 3) swap(*pos[a],*pos[b]), swap(pos[a], pos[b]); // ����
            else {
                l.erase(pos[a]); // �Ȳ���
                if (inv == 1) op = 3 - op; // ��ת�����ҽ���
                auto p=pos[b];
                if (op == 2) p ++; // �����Ҳ�
                pos[a] = l.insert(p, a); // a����λ��
            }
        }
        long long cnt=1, oddsum=0; // �������
        for (auto p=l.begin(); p != l.end(); p++, cnt++) {
            if (cnt % 2 == 1) oddsum += *p;
        }
        printf("Case %d: %lld\n", ++num, (inv == 1 && n%2 == 0) ?  (long long)n*(n+1)/2-oddsum : (long long)oddsum);
    }
    return 0;
}

