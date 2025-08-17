#include<stdio.h>
#include<string.h>

#define Max 100000

int main()
{
    char a[Max],b[Max];
    
    int aFlag;
    int bFlag;
    int aLast,bLast;
    while (scanf("%s%s", a, b) != EOF){
    	aFlag = 0;
    	bFlag = 0;

    	for(int i=0;i<strlen(a);i++){//如果a是小数就将标志位置为1 
    		if(a[i]=='.') aFlag = 1;
		}
    	for(int j=0;j<strlen(b);j++){//如果b是小数就将标志位置为1 
    		if(b[j]=='.') bFlag = 1;
		}
		
    	if(aFlag){//a是小数的处理，就是将小数后面的0给去掉 
    		aLast = strlen(a)-1;//这个数的最后一位的下标值 
    		while(a[aLast]=='0'){
    			a[aLast]='\0';
    			aLast--;
			}
			if(a[aLast]=='.'){//如果检测到如0.00的情况，就一直将“.”也给去掉 
				a[aLast]='\0';
			}
		}
		
    	if(bFlag){//如上 
    		bLast = strlen(b)-1;
    		while(b[bLast]=='0'){
    			b[bLast]='\0';
    			bLast--;
			}
			if(b[bLast]=='.'){
				b[bLast]='\0';
			}
		}
		if(strcmp(a,b)==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
    }
    return 0;
}

