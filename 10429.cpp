#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
using namespace std;
struct moo
{
    int x,y;
};
typedef struct moo moo;
vector <moo> v;
char str[5][6];
char visit[3][3];
char ans[33];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int n,m;
void dfs(int x,int y,int d);
int chk(char *str);
int main(void)
{
    scanf("%d%d\n",&n,&m);
    for(int i=0;i<3;i++)
        scanf("%s\n",str[i]);
    for(int i=0;i<3;i++)
    {
        for(int j=0;j<3;j++)
        {
            if((i+j)%2)
                continue;
            dfs(i,j,0);
        }
    }
    printf("0\n");
    return 0;
}
void dfs(int x,int y,int d)
{
    moo I;
    
    ans[d] = str[x][y]; 
    visit[x][y] = 1; I.x=x; I.y=y; v.push_back(I); 
    
    if(d == 2*m-2)
    {
        if(chk(ans) == n)
        {
            printf("1\n");
            for(int i=0;i<(int)v.size();i++)
                printf("%d %d\n",v[i].x,v[i].y);
            exit(0);
        }
        visit[x][y] = 0; v.pop_back();
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int tx = x + dx[i]; int ty = y + dy[i];
        if(tx<0||ty<0||tx>=3||ty>=3||visit[tx][ty])
            continue;
        dfs(tx,ty,d+1);
    }
    visit[x][y] = 0; v.pop_back();
}
int chk(char *ans)
{
    int res = ans[0] - '0'; int len = strlen(ans);
    for(int i=2;i<len;i = i+2)
    {
        int v = ans[i] - '0';
        if(ans[i-1] == '-')
            res = res - v;
        else
            res = res + v;
    }
    return res;
}
