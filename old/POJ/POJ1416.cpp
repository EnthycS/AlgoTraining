// POJ 1416
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int tar, num, Len, ans, minn;
bool ok, take;
int in[102], Ans[102];
int cnt_in, cnt_ans;

void setLen(){ // Len ��¼���Լ��벻���ĳ���
    Len = 0;
    int q = num;
    while(q){ Len++; q /= 10; }
}

void dfs(int r, int len, int tot){ // r:��ǰֽ�� len:�ж����ڼ������� tot:���º���ܺ�
    if(len == Len){ // �жϵ���������
        tot += r; // ��������r
        if(r != 0) // ������� 0 Ҫ������(�����Ӧ)
            in[cnt_in++] = r;

        if(tot <= tar){ // ��Ҫ��Ŀ��ֵС
            if(tar-tot < minn){ // Ȼ���Ҳ�ֵ��С��
                ok = true;
                minn = tar - tot;
                ans = tot;
                for(int i = 0; i < cnt_in; i++) Ans[i] = in[i]; cnt_ans = cnt_in;
                take = false; // ���º�����µĴ����� take ҲҪ�ı�
                // ���ݸ���
            }
            else if(tar - tot == minn) { // �������ͬ�Ĳ�ֵ �ж��Ƿ��ظ�(�������Ԫ����һ��������)
                bool equ = true;
                if(cnt_ans == cnt_in){
                    for(int i = 0; i < cnt_in; i++){
                        if(Ans[i] != in[i]) {
                            equ = false;
                        }
                    }
                }
                else equ = false;
                if(!equ) take = true;
            }
        }
        if(r != 0)
            cnt_in--; // ͬ��Ҳ�ǻ���
        return ;
    }

    // ��¼��ǰ r �ĳ���
    int q = r, now = 0;
    while(q){ now++; q /= 10; }
    int pla = len - (Len - now); // Ӧ�����Ҽ�λ��ȡ����(�����������Լ�������һ��)
    int zero = 1;
    for(int i = 0; i < Len - len - 1; i++) zero *= 10;

    // ��λ��
    int cro = r / zero; // ������������
    in[cnt_in++] = cro; // �Ž�������(˳���˼·)
    dfs(r % zero, len + 1, tot + cro);
    cnt_in--; // ����,����

    // ��λ����
    if(len == Len - 1 && num % 10 == 0 && r == 0) in[cnt_in++] = r; // ���У��ж�ԭ�������һλ�Ƿ�Ϊ0�������Ҫ������(ȡ��������ж�ʱ���ж�����)
    dfs(r, len + 1, tot);
    if(len == Len - 1 && num % 10 == 0 && r == 0)cnt_in--; // �������еĻ���

}

int main()
{
    while(~scanf("%d %d", &tar, &num) && tar + num){
        // ��ʼ������
        memset(in, 0, sizeof(in));
        memset(Ans, 0, sizeof(Ans));
        cnt_in = cnt_ans = 0;
        ok = take = false; // ok ��¼����������� take ��¼�Ƿ����ظ�����������
        ans = 0;
        minn = 0x3f3f3f3f;
        setLen();

        // �ܳ���ֻ����һ��dfs()
        dfs(num, 0, 0);

        // �����
        if(ok && !take) {
            printf("%d ", ans);
            for(int i = 0; i < cnt_ans; i++)
                printf("%d%c", Ans[i], i == cnt_ans - 1 ? '\n' : ' ');
        }
        else if(ok && take) printf("rejected\n");
        else if(!ok) printf("error\n");
    }
    return 0;
}


