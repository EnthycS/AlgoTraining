// POJ 1416
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int tar, num, Len, ans, minn;
bool ok, take;
int in[102], Ans[102];
int cnt_in, cnt_ans;

void setLen(){ // Len 记录可以剪与不剪的长度
    Len = 0;
    int q = num;
    while(q){ Len++; q /= 10; }
}

void dfs(int r, int len, int tot){ // r:当前纸条 len:判定到第几个数上 tot:剪下后的总和
    if(len == Len){ // 判断到最后的数字
        tot += r; // 加上最后的r
        if(r != 0) // 如果不是 0 要入数组(下面对应)
            in[cnt_in++] = r;

        if(tot <= tar){ // 先要比目标值小
            if(tar-tot < minn){ // 然后找差值最小的
                ok = true;
                minn = tar - tot;
                ans = tot;
                for(int i = 0; i < cnt_in; i++) Ans[i] = in[i]; cnt_ans = cnt_in;
                take = false; // 更新后就有新的答案数组 take 也要改变
                // 数据更新
            }
            else if(tar - tot == minn) { // 如果是相同的差值 判断是否重复(如果数组元素是一样的则不算)
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
            cnt_in--; // 同样也是回溯
        return ;
    }

    // 记录当前 r 的长度
    int q = r, now = 0;
    while(q){ now++; q /= 10; }
    int pla = len - (Len - now); // 应该往右几位截取数据(这个规则可以自己动手算一算)
    int zero = 1;
    for(int i = 0; i < Len - len - 1; i++) zero *= 10;

    // 该位切
    int cro = r / zero; // 被剪下来的数
    in[cnt_in++] = cro; // 放进数组里(顺序表思路)
    dfs(r % zero, len + 1, tot + cro);
    cnt_in--; // 回溯,丢掉

    // 该位不切
    if(len == Len - 1 && num % 10 == 0 && r == 0) in[cnt_in++] = r; // 特判：判断原字条最后一位是否为0，如果是要入数组(取决于最后判断时的判断条件)
    dfs(r, len + 1, tot);
    if(len == Len - 1 && num % 10 == 0 && r == 0)cnt_in--; // 对于特判的回溯

}

int main()
{
    while(~scanf("%d %d", &tar, &num) && tar + num){
        // 初始化工作
        memset(in, 0, sizeof(in));
        memset(Ans, 0, sizeof(Ans));
        cnt_in = cnt_ans = 0;
        ok = take = false; // ok 记录有满足的条件 take 记录是否有重复的满足条件
        ans = 0;
        minn = 0x3f3f3f3f;
        setLen();

        // 跑程序只是有一个dfs()
        dfs(num, 0, 0);

        // 答案输出
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


