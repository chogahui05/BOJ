#include <stdio.h>
#include <vector>
#define inf 0x3f3f3f3f
using namespace std;
vector <int> con[100];
int f[100];
int arr[100];
int n,m,k,mmx = -inf;
void work(int sum,int lo,int depth);
void init();
int chk(int cur);
int main(void)
{
    scanf("%d%d%d",&n,&m,&k); init();
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            scanf("%d",&(arr[i*m+j]));
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            f[i*m+j] = 1;
            work(arr[i*m+j],i*m+j,1);
            f[i*m+j] = 0;
        }
    }
    printf("%d\n",mmx);
}
void init()
{
    //LEFT
    for(int i=0;i<n;i++)
        for(int j=1;j<m;j++)
            con[i*m+j].push_back(i*m+(j-1));
    //UP
    for(int i=1;i<n;i++)
        for(int j=0;j<m;j++)
            con[i*m+j].push_back((i-1)*m+j);
}
void work(int sum,int lo,int depth)
{
    if(depth == k)
    {
        if(sum > mmx) mmx = sum;
        return;
    }
    for(int i=lo+1;i<n*m;i++)
    {
        if(chk(i))
            continue;
        f[i] = 1;
        work(sum + arr[i],i,depth+1);
        f[i] = 0;
    }
}
int chk(int cur)
{
    for(int i=0;i<(int)con[cur].size();i++)
    {
        if(f[con[cur][i]])
            return 1;
    }
    return 0;
}
