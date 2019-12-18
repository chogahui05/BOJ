#include <stdio.h>
#include <string.h>
#include <memory.h>
#include <vector>
using namespace std;
struct moo
{
    int sz;
    int merge;
};
typedef struct moo moo;
int arr[20][20];
vector <moo> v;
vector <moo> u;
char str[30];
void up(int);
void down(int);
void left(int);
void right(int);
void build();
int main(void)
{
    int T,n; scanf("%d\n",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d %s\n",&n,str);
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                scanf("%d",&(arr[i][j]));
        if(strcmp(str,"left") == 0)
            left(n);
        else if(strcmp(str,"right") == 0)
            right(n);
        else if(strcmp(str,"up") == 0)
            up(n);
        else
            down(n);
        printf("Case #%d:\n",t);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",arr[i][j]);
            }
            printf("\n");
        }
    }
}
void build()
{
    moo I; u.clear();
    if((int)v.size() == 0)
        return;
    u.push_back(v[0]);
    for(int i=1;i<(int)v.size();i++)
    {
        //NOT MERGE
        if(u[(int)u.size()-1].merge || u[(int)u.size()-1].sz != v[i].sz)
            u.push_back(v[i]);
        //MERGE
        else
        {
            u.pop_back(); I.sz = v[i].sz*2; I.merge = 1; u.push_back(I);
        }
    }
}
void up(int n)
{
    moo I;
    for(int c=0;c<n;c++)
    {
        v.clear();
        for(int r=0;r<n;r++)
        {
            if(arr[r][c] == 0)
                continue;
            I.sz = arr[r][c]; I.merge = 0; v.push_back(I); arr[r][c] = 0;
        }
        build();
        for(int r=0,p=0;p<(int)u.size();p++,r++)
            arr[r][c] = u[p].sz;
    }
}
void down(int n)
{
    moo I;
    for(int c=0;c<n;c++)
    {
        v.clear();
        for(int r=n-1;r>=0;r--)
        {
            if(arr[r][c] == 0)
                continue;
            I.sz = arr[r][c]; I.merge = 0; v.push_back(I); arr[r][c] = 0;
        }
        build();
        for(int r=n-1,p=0;p<(int)u.size();p++,r--)
            arr[r][c] = u[p].sz;
    }
}
void left(int n)
{
    moo I;
    for(int r=0;r<n;r++)
    {
        v.clear();
        for(int c=0;c<n;c++)
        {
            if(arr[r][c] == 0)
                continue;
            I.sz = arr[r][c]; I.merge = 0; v.push_back(I); arr[r][c] = 0;
        }
        build();
        for(int c=0,p=0;p<(int)u.size();p++,c++)
            arr[r][c] = u[p].sz;
    }
}
void right(int n)
{
    moo I;
    for(int r=0;r<n;r++)
    {
        v.clear();
        for(int c=n-1;c>=0;c--)
        {
            if(arr[r][c] == 0)
                continue;
            I.sz = arr[r][c]; I.merge = 0; v.push_back(I); arr[r][c] = 0;
        }
        build();
        for(int c=n-1,p=0;p<(int)u.size();p++,c--)
            arr[r][c] = u[p].sz;
    }
}
