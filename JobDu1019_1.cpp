#include "stdio.h"
#include "string.h"
#define MAX 1001


// The code of God. 
double stack[MAX];
int tail;

int main(){
  int a;
  while(scanf("%d ",&a)&&a!=0){
   tail=0;
   stack[++tail]=1.0*a;//tailʼ��ָ��ĩβ����λ��
  //1.��ջ�������ݣ��������*/�ţ�ֻ����ջβ��
   char ch1,ch2;
   while(scanf("%c %d%c",&ch1,&a,&ch2)!=EOF){
    if(ch1=='+'){
     stack[++tail]=1.0*a;//push
    }else if(ch1=='-'){
     stack[++tail]=-1.0*a;//push neg
    }else if(ch1=='*'){
     stack[tail]=stack[tail]*a;//update tail
    }else if(ch1=='/'){
     stack[tail]=stack[tail]/(double)a;//updata tail
    }
    if(ch2!=' ')break; 
  }
//2.��ջ��ͷ�Ķ���ȫ�������������
  double result=0;
  for(int i=1;i<=tail;i++)result+=stack[i];
  printf("%.2lf\n",result);
  }
return 1;
}
