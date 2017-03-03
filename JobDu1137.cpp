#include <stdio.h>
#include <string.h>

char s1[101],s2[101];
int  a[101],b[101],ans_d[101],ans_i[101];

int main()
{
    int n;
    scanf("%d",&n);
    while (n--)
    {
        scanf("%s %s",s1,s2);
        int alen=strlen(s1), blen=strlen(s2);
        int ap,bp;                                      
        for (int i=0;i<alen;++i)                       //求小数点的位置 
            if (s1[i]=='.') ap=i;
        for (int i=0;i<blen;++i)
            if (s2[i]=='.') bp=i;
        int ansp_len,asize=0,bsize=0;
        if (alen-ap>blen-bp)                           //将小数部分对齐 
        {
            ansp_len=alen-1-ap;
            for (int i=0;i<alen-ap-(blen-bp);++i)
                b[bsize++]=0;
        }
        else
        {
            ansp_len=blen-1-bp;
            for (int i=0;i<blen-bp-(alen-ap);++i)
                a[asize++]=0;
        }
        for (int i=alen-1;i>ap;--i)
            a[asize++]=s1[i]-'0';
        for (int i=blen-1;i>bp;--i)
            b[bsize++]=s2[i]-'0';                        
        int carry=0,temp;
        for (int i=0;i<ansp_len;++i)                    //小数部分相加 
        {
            temp=a[i]+b[i]+carry;
            ans_d[i]=temp%10;
            carry=temp/10;
        }
        int intlen;
        asize=bsize=0;
        for (int i=ap-1;i>=0;--i)                       //整数部分对齐 
            a[asize++]=s1[i]-'0';
        for (int i=bp-1;i>=0;--i)
            b[bsize++]=s2[i]-'0';
        if (ap>bp)
        {
            intlen=ap;
            for (int i=0;i<ap-bp;++i)
                b[bsize++]=0;
        }
        else
        {
            intlen=bp;
            for (int i=0;i<bp-ap;++i)
                a[asize++]=0;
        }
        for (int i=0;i<intlen;++i)                        //整数部分相加 
        {
            temp=a[i]+b[i]+carry;
            ans_i[i]=temp%10;
            carry=temp/10;
        }
        if (carry!=0) ans_i[intlen++]=carry;
        for (int i=intlen-1;i>=0;--i)
            printf("%d",ans_i[i]);
        printf(".");
        int end=0;
        while (ans_d[end]==0) ++end;                     //小数部分去尾零 
        for (int i=ansp_len-1;i>=end;--i)
            printf("%d",ans_d[i]);
        printf("\n");
    }
    return 0;
}
