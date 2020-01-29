#include <stdio.h>
#include <vector>
using namespace std;
vector <int> db[33];
int sc[33];
int go[10];
int MAL_op[10];
int mmx = 0;
void init_go();
void init_score();
void process();
void work(int depth);
void add(int cur,int a,int b,int c,int d,int e);
int main(void)
{
    init_go(); init_score();
    for(int i=0;i<10;i++)
        scanf("%d",&(go[i]));
    work(0);
    printf("%d\n",mmx);
}
void process()
{
    int cur_location[4] = {0};
    int MAL_co[42] = {4};
    int r = 0;
    for(int i = 0; i<10; i++)
    {
        int mal = MAL_op[i];
        int su = go[i];
        int cur_pos = cur_location[mal];
        int next_pos = db[cur_pos][su];
        if(next_pos == 32 || MAL_co[next_pos] == 0)
        {
            MAL_co[cur_pos]--; MAL_co[next_pos]++;
            cur_location[mal] = next_pos;
            r = r + sc[next_pos];
        }
        else
            return;
    }
    if(r>mmx)
        mmx = r;
}
void work(int depth)
{
    if(depth == 10)
    {
        process();
        return;
    }
    for(int i=0;i<4;i++)
    {
        MAL_op[depth] = i;
        work(depth+1);
    }
}
void init_score()
{
    for(int i=1;i<=20;i++)
        sc[i] = 2*i;
    sc[21] = 22; sc[22] = 24; sc[23] = 25;
    sc[24] = 13; sc[25] = 16; sc[26] = 19;
    sc[27] = 28; sc[28] = 27; sc[29] = 26;
    sc[30] = 30; sc[31] = 35;
}
void init_go()
{
    for(int i=0;i<=32;i++)
        db[i].push_back(i);
    add(0,1,2,3,4,5); add(1,2,3,4,5,6); add(2,3,4,5,6,7); add(3,4,5,6,7,8); add(4,5,6,7,8,9);
    add(5,24,25,26,23,30); 
    
    add(6,7,8,9,10,11); add(7,8,9,10,11,12); add(8,9,10,11,12,13); add(9,10,11,12,13,14);
    add(10,21,22,23,30,31);
    
    add(11,12,13,14,15,16); add(12,13,14,15,16,17); add(13,14,15,16,17,18); add(14,15,16,17,18,19);
    add(15,27,28,29,23,30);
    
    add(16,17,18,19,20,32); add(17,18,19,20,32,32); add(18,19,20,32,32,32); add(19,20,32,32,32,32);
    add(20,32,32,32,32,32);
    
    add(21,22,23,30,31,20); add(22,23,30,31,20,32); add(23,30,31,20,32,32); add(24,25,26,23,30,31);
    add(25,26,23,30,31,20); add(26,23,30,31,20,32); add(27,28,29,23,30,31); add(28,29,23,30,31,20);
    add(29,23,30,31,20,32); add(30,31,20,32,32,32); add(31,20,32,32,32,32);
    
    add(32,32,32,32,32,32);
}
void add(int cur,int a,int b,int c,int d,int e)
{
    db[cur].push_back(a); db[cur].push_back(b); 
    db[cur].push_back(c); db[cur].push_back(d); db[cur].push_back(e);
}
