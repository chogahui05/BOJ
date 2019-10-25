#include <stdio.h>
#include <string.h>
#include <memory.h>
#define inf 0x3f3f3f3f
struct moo
{
    int x,y;
};
typedef struct moo moo;
int dp[1001][1001];
moo wif[1001][1001];
char pat[1001][5];
char left[5];
char right[5];
int ans[1001];
int go(char *str);
int calc(int a,int b);
int Le(int f,int t);
int Ri(int f,int t);
int main(void)
{
    int n,mmn=inf,r,x,y,cx,cy,p; scanf("%s %s\n%d\n",left,right,&n); memset(dp,-1,sizeof(int)*1001*1001);
    dp[0][0] = 0;
    for(int i=1;i<=1000;i++)
        dp[i][i] = inf;
    for(int i=1;i<=n;i++)
        scanf(" %s",pat[i]);
    for(int i=0;i<=n;i++)
    {
        r = calc(i,n);
        if(r<mmn) {mmn = r; x=i; y=n;}
        r = calc(n,i);
        if(r<mmn) {mmn = r; x=n; y=i;}
    }
    printf("%d\n",mmn); p=n;
    while(x||y)
    {
        cx = x; cy = y;
        x = wif[cx][cy].x; y = wif[cx][cy].y;
        if(cx!=x)
            ans[p] = 1;
        else
            ans[p] = 2;
        p--;
    }
    for(int i=1;i<=n;i++)
        printf("%d ",ans[i]);
    return 0;
}
int calc(int a,int b)
{
    int mmn = inf;
    if(dp[a][b]!=-1)
        return dp[a][b];
    if(a>b+1) //7 5
    {
        mmn = calc(a-1,b) + Le(a-1,a);
        wif[a][b].x = a-1; wif[a][b].y = b;
    }
    else if(b>a+1) //5 7
    {
        mmn = calc(a,b-1) + Ri(b-1,b);
        wif[a][b].x = a; wif[a][b].y = b-1;
    }
    else if(a>b) //6 5
    {
        for(int i=0;i<=b;i++)
        {
            int r = calc(i,b) + Le(i,a);
            if(r<mmn)
            {
                wif[a][b].x = i; wif[a][b].y = b; mmn = r;
            }
        }
    }
    else if(b>a) //5 6
    {
        for(int i=0;i<=a;i++)
        {
            int r = calc(a,i) + Ri(i,b);
            if(r<mmn)
            {
                wif[a][b].x = a; wif[a][b].y = i; mmn = r;
            }
        }
    }
    dp[a][b] = mmn;
    return mmn;
}
int Le(int f,int t)
{
    int a,b;
    if(f == 0)
        a = go(left);
    else
        a = go(pat[f]);
    b = go(pat[t]);
    if(a>b)
        return a-b;
    return b-a;
}
int Ri(int f,int t)
{
    int a,b;
    if(f == 0)
        a = go(right);
    else
        a = go(pat[f]);
    b = go(pat[t]);
    if(a>b)
        return a-b;
    return b-a;
}
int go(char *str)
{
    int len = strlen(str);
    char po[7] = {9,11,0,2,4,5,7};
    return po[(str[0]-'A')] + 12*(str[1]-'0') + (len == 3);
}
