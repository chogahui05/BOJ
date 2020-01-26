#include <stdio.h>
#include <memory.h>
#include <queue>
#include <vector>
using namespace std;
struct moo
{
    int x,y;
};
typedef struct moo moo;
char str[100][11];
char visit[100][11];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
queue <moo> Q;
vector <moo> v;
int work(int n,int k);
void bfs(int x,int y,int n);
void upd(int n);
void print(int n);
int main(void)
{
    int n,k; scanf("%d%d\n",&n,&k);
    for(int i=0;i<n;i++)
        scanf("%s\n",str[i]);
    while(work(n,k)) upd(n);
    print(n);
}
void print(int n)
{
    for(int i=0;i<n;i++)
        printf("%s\n",str[i]);
}
void upd(int n)
{
    for(int j=0;j<10;j++)
    {
        int po = n-1;
        for(int i=n-1;i>=0;i--)
        {
            if(str[i][j]!='0')
                str[po--][j] = str[i][j];
        }
        for(int i=po;i>=0;i--)
            str[i][j] = '0';
    }
}
int work(int n,int k)
{
    int ret = 0;
    memset(visit,0,sizeof(char)*100*11);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<10;j++)
        {
            if(str[i][j] == '0' || visit[i][j])
                continue;
            bfs(i,j,n);
            if((int)v.size()<k)
                continue;
            for(int ki=0;ki<(int)v.size();ki++)
            {
                int x = v[ki].x; int y = v[ki].y;
                str[x][y] = '0';
                ret++;
            }
        }
    }
    return ret;
}
void bfs(int x,int y,int n)
{
    moo I,C; v.clear(); char ch = str[x][y]; visit[x][y] = 1; I.x=x; I.y=y; Q.push(I);
    while(!Q.empty())
    {
        C = Q.front(); Q.pop(); v.push_back(C);
        for(int i=0;i<4;i++)
        {
            int tx = C.x + dx[i];
            int ty = C.y + dy[i];
            if(tx<0||ty<0||tx>=n||ty>=10||visit[tx][ty])
                continue;
            if(str[tx][ty]!=ch)
                continue;
            visit[tx][ty] = 1; I.x = tx; I.y = ty; Q.push(I);
        }
    }
}
