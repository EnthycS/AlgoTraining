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

    	for(int i=0;i<strlen(a);i++){//���a��С���ͽ���־λ��Ϊ1 
    		if(a[i]=='.') aFlag = 1;
		}
    	for(int j=0;j<strlen(b);j++){//���b��С���ͽ���־λ��Ϊ1 
    		if(b[j]=='.') bFlag = 1;
		}
		
    	if(aFlag){//a��С���Ĵ������ǽ�С�������0��ȥ�� 
    		aLast = strlen(a)-1;//����������һλ���±�ֵ 
    		while(a[aLast]=='0'){
    			a[aLast]='\0';
    			aLast--;
			}
			if(a[aLast]=='.'){//�����⵽��0.00���������һֱ����.��Ҳ��ȥ�� 
				a[aLast]='\0';
			}
		}
		
    	if(bFlag){//���� 
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

