#include <stdio.h>
#include <vector>
using namespace std;
struct moo
{
    int s,e;
};
typedef struct moo moo;
vector <moo> add[30020];
vector <moo> del[30020];
int seg[1<<16];
int depth[1<<16];
void update(int le,int ri,int node_num,int node_s,int node_e,int diff);
void upd(int node_num,int node_s,int node_e,int value);
int main(void)
{
    int n,x1,y1,x2,y2,ans=0; moo I; scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
        I.s = y1; I.e = y2-1; add[x1].push_back(I); del[x2].push_back(I);
    }

    for(int i=0;i<30020;i++)
    {
        for(int j=0;j<(int)add[i].size();j++)
        {
            int s = add[i][j].s; int e = add[i][j].e;
            update(s,e,0,0,(1<<15)-1,1);
        }
        for(int j=0;j<(int)del[i].size();j++)
        {
            int s = del[i][j].s; int e = del[i][j].e;
            update(s,e,0,0,(1<<15)-1,-1);
        }
        ans = ans + seg[0];
    }
    printf("%d\n",ans);
}
void update(int le,int ri,int node_num,int node_s,int node_e,int diff)
{
    int mid = (node_s + node_e)/2;
    int numi = (node_e - node_s + 1);
    if(ri<node_s||node_e<le)
        return;
    if(le<=node_s&&node_e<=ri)
    {
        depth[node_num] += diff;
        upd(node_num,node_s,node_e,numi);
        return;
    }
    update(le,ri,2*node_num+1,node_s,mid,diff);
    update(le,ri,2*node_num+2,mid+1,node_e,diff);
    upd(node_num,node_s,node_e,numi);
}
void upd(int node_num,int node_s,int node_e,int value)
{
    if(depth[node_num])
    {
        seg[node_num] = value;
        return;
    }
    if(node_s == node_e)
    {
        seg[node_num] = 0;
        return;
    }
    seg[node_num] = seg[2*node_num+1] + seg[2*node_num+2];
}
