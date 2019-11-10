#include <stdio.h>
#include <memory.h>
#include <vector>
#define inf 0x3f3f3f3fLL
using namespace std;
struct moo
{
    int s,e;
};
typedef struct moo moo;
int arr[18][18];
int dp[17][17][50000];
int dp2[18][18][18][18];
vector <moo> v;
vector <int> u;
int calc(int,int,int,int);
int cc(int,int,int,int);
int _count(int);
int main(void)
{
    int n,m,r,c; scanf("%d%d%d%d",&n,&m,&r,&c); memset(dp,-1,sizeof(int)*17*17*50000);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&(arr[i][j]));
    for(int x1=0;x1<n;x1++)
        for(int y1=0;y1<m;y1++)
            for(int x2=x1;x2<n;x2++)
                for(int y2=y1;y2<m;y2++)
                    dp2[x1][y1][x2][y2] = cc(x1,y1,x2,y2);
    for(int state=1; state<=(1<<(m-1))-1; state++)
    {
        if(_count(state)!=c)
            continue;
        u.push_back(state);
    }
    for(int i=0;i<n;i++)
        for(int j=0;j<(int)u.size();j++)
            dp[0][i][j] = calc(0,i,u[j],m);
    for(int i=1;i<=r;i++)
    {
        for(int xx=i;xx<n;xx++)
        {
            for(int j=0;j<(int)u.size();j++)
            {
                //dp[i][xx][st]
                int mmn = inf;
                for(int from = i; from <= xx; from++)
                {
                    int a = dp[i-1][from-1][j]; int b = calc(from,xx,u[j],m);
                    int re = ((a>b)?a:b);
                    if(re<mmn)
                        mmn = re;
                }
                dp[i][xx][j] = mmn;
            }
        }
    }
    int mmn = inf;
    for(int i=0;i<(int)u.size();i++)
    {
        if(dp[r][n-1][i]<mmn)
            mmn = dp[r][n-1][i];
    }
    printf("%d\n",mmn);
    return 0;
}
int _count(int s)
{
    int cc = 0;
    for(int i=0;i<20;i++)
        cc = cc + ((s&(1<<i))!=0);
    return cc;
}
int calc(int from,int to,int state,int m)
{
    v.clear(); int prev = 0,mmx = 0; moo I;
    for(int i=0;i<18;i++)
    {
        if((state&(1<<i)) == 0)
            continue;
        I.s = prev; I.e = i; v.push_back(I); prev = i+1;
    }
    I.s = prev; I.e = m-1; v.push_back(I);
    for(int i=0;i<(int)v.size();i++)
    {
        int r = dp2[from][v[i].s][to][v[i].e];
        if(r>mmx)
            mmx = r;
    }
    return mmx;
}
int cc(int x1,int y1,int x2,int y2)
{
    int mmx = 0;
    for(int x=x1;x<=x2;x++)
    {
        for(int y=y1;y<=y2;y++)
        {
            mmx += arr[x][y];
        }
    }
    return mmx;
}
