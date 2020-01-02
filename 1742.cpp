#include <stdio.h>
#include <memory.h>
#include <vector>
#include <queue>
#define M 1000003LL
using namespace std;
typedef long long ll;
vector <ll> con[31];
vector <ll> con2[31];
vector <ll> yy[31];
vector <ll> vs;
queue <ll> Q;
ll C[31][31];
char visit[31];
ll dp[1<<16];
void do_bfs(ll x,ll ys);
ll calc(ll lo);
ll work(ll state,ll sz);
void init();
int main(void)
{
    ll n,m,a,b,ys=0,ans=1,tot; scanf("%lld%lld",&n,&m); tot = n; init();
    for(ll i=1;i<=m;i++)
    {
        scanf("%lld%lld",&a,&b); con[a].push_back(b); con2[a].push_back(b); con2[b].push_back(a);
    }
    for(ll i=1;i<=n;i++)
    {
        if(visit[i])
            continue;
        do_bfs(i,ys); ys++;
    }
    for(int i=0;i<ys;i++)
    {
        ll sz = (ll)yy[i].size();
        ll r = calc(i); r = r % M;
        r = r*C[tot][sz]; r = r % M;
        ans = ans * r; ans = ans % M;
        tot = tot - sz;
    }
    printf("%lld\n",ans);
    return 0;
}
void init()
{
    for(ll i=0;i<=30;i++)
        C[i][0] = C[i][i] = 1;
    for(ll i=2;i<=30;i++)
        for(ll j=1;j<i;j++)
            C[i][j] = C[i-1][j] + C[i-1][j-1];
}
ll calc(ll lo)
{
    memset(dp,-1,sizeof(ll)*(1<<16)); vs.clear();
    for(ll i=0;i<(ll)yy[lo].size();i++)
        vs.push_back(yy[lo][i]);
    ll sz = (ll)yy[lo].size();
    work((1<<sz)-1,sz);
    return dp[(1<<sz)-1];
}
ll work(ll state,ll sz)
{
    ll r = 0;
    if(state == 0)
    {
        dp[state] = 1;
        return 1;
    }
    if(dp[state]!=-1)
        return dp[state];
    char in[31] = {0};
    for(ll i=0;i<sz;i++)
    {
        if((state&(1<<i)) == 0)
            continue;
        ll cur = vs[i];
        for(ll i=0;i<(ll)con[cur].size();i++)
        {
            ll next = con[cur][i]; in[next]++;
        }
    }
    for(ll i=0;i<sz;i++)
    {
        if((state&(1<<i)) == 0 || in[vs[i]] > 0)
            continue;
        ll new_state = (state&(~(1<<i)));
        r = r + work(new_state,sz);
    }
    dp[state] = r; return r;
}
void do_bfs(ll x,ll ys)
{
    visit[x] = 1; Q.push(x);
    while(!Q.empty())
    {
        int C = Q.front(); Q.pop(); yy[ys].push_back(C);
        for(int i=0;i<(int)con2[C].size();i++)
        {
            int next = con2[C][i];
            if(visit[next])
                continue;
            Q.push(next); visit[next] = 1;
        }
    }
}
