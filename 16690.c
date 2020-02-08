#include <stdio.h>
#include <memory.h>
#define inf 0x3f3f3f3f
char dp[18][1<<18];
int memo[30][30][30];
char str[20];
char pat[20];
int calc(int lo,int state,int m);
int is_equal(int s1,int s2,int sub_len);
int main(void)
{
    memset(dp,-1,sizeof(char)*18*(1<<18)); memset(memo,-1,sizeof(int)*30*30*30); scanf("%s\n%s",str,pat); 
    int len1 = strlen(str); int len2 = strlen(pat);
    printf("%d\n",calc(len2-1,(1<<len1)-1,len2)-1);
}
int calc(int lo,int state,int m)
{
    int mmn = inf;
    //printf("%d %d\n",lo,state);
    if(lo < 0)
    {
        if(state == 0)
            return 0;
        return inf;
    }
    if(dp[lo][state]!=-1)
        return dp[lo][state];
    for(int i=0;i<=lo;i++)
    {
        //[i, lo]
        int sub_len = lo - i + 1;
        int mask = (1<<sub_len) - 1;
        for(int j=0;j<m;j++,mask = mask*2)
        {
            //[j, j + sub_len - 1]
            //state = 01101111100000
            //mask  = 00000111100000
            if((state & mask) != mask)
                continue;
            int new_state = (state & (~mask));
            if(is_equal(i,j,sub_len) == 0)
                continue;
            
            int r = 1 + calc(i-1,new_state,m);
            //printf("%d %d : %d %d\n",lo,state,i-1,new_state);
            //printf("state = %d mask = %d lo = %d\n",state,mask,lo);
            if(r<mmn) mmn = r;
        }
    }
    dp[lo][state] = mmn;
    return mmn;
}
int is_equal(int s1,int s2,int sub_len)
{
    int flag = 1;
    if(memo[s1][s2][sub_len]!=-1)
        return memo[s1][s2][sub_len];
    for(int i=0;i<sub_len;i++)
    {
        if(str[s1+i] != pat[s2 + i])
        {
            flag = 0; break;
        }
    }
    memo[s1][s2][sub_len] = flag;
    return flag;
}
