#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

char a[120];
int main()
{
    while(gets(a))
    {
        int p = strlen(a);
        for(int i = 0;i < p;i++)
        {
            if(a[i] == ' ')
            {
                int j = i + 1;
                a[j] = a[j] - 32;
            }

            if(i==0)
                a[i] = a[i] - 32;
            cout<<a[i];
        }
        cout<<endl;
    }
    return 0;
}
