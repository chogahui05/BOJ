#include <stdio.h>
#include <memory.h>
char str[100][100];
char real_map[100][100]; //Wall, Mok, empty
char real_box[100][100]; //Wall, Box, Character, empty
char op[101];
int dx[128];
int dy[128];
void init();
char state(int x,int y);
void build_real_map(int n,int m);
void build_real_box(int n,int m);
int find_character(int n,int m);
int is_complete(int n,int m);
int main(void)
{
    int n,m,x,y,tc=1,flag;
    init();
    while(1)
    {
        scanf("%d%d\n",&n,&m); flag = 0;
        if(n == 0 && m == 0)
            break;
        for(int i=0;i<n;i++)
            scanf("%s\n",str[i]);
        build_real_map(n,m);
        build_real_box(n,m);
        //Okay. I Will move the character real_box_map
        int ri = find_character(n,m); x = ri/m; y = ri%m;
        scanf("%s\n",op);
        for(int i=0;op[i];i++)
        {
            int tx = x + dx[op[i]]; int ty = y + dy[op[i]];
            //Case 1 : Empty
            if(state(tx,ty) == '.' || state(tx,ty) == '+')
            {
                real_box[tx][ty] = 'W'; real_box[x][y] = '.';
                x = tx; y = ty;
            }
            //Case 2 : WALL
            else if(real_box[tx][ty] == '#') //That's a WALL
                ; //Not Move
            //Case 3 : Box
            else if(real_box[tx][ty] == 'B')
            {
                int tx2 = tx + dx[op[i]]; int ty2 = ty + dy[op[i]];
                //IF Moving space is EMPTY
                if(state(tx2,ty2) == '.' || state(tx2,ty2) == '+')
                {
                    real_box[tx2][ty2] = 'B';
                    real_box[tx][ty] = 'W'; //THAT
                    real_box[x][y] = '.';
                    x = tx; y = ty;
                }
            }
            if(is_complete(n,m))
            {
                flag = 1;
                break;
            }
        }
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                str[i][j] = state(i,j);
        
        printf("Game %d: %scomplete\n",tc,flag?"":"in");
        for(int i=0;i<n;i++)
            printf("%s\n",str[i]);
        tc++;
    }
}
int is_complete(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(state(i,j) == '+' || state(i,j) == 'b')
                return 0;
        }
    }
    return 1;
}
char state(int x,int y)
{
    if(real_map[x][y] == '#') //OKAY. THIS IS WALL
        return '#';
    if(real_box[x][y] == 'W')
    {
        if(real_map[x][y] == '+')
            return 'W';
        return 'w';
    }
    if(real_box[x][y] == 'B')
    {
        if(real_map[x][y] == '+')
            return 'B';
        else
            return 'b';
    }
    if(real_map[x][y] == '+')
        return '+';
    return '.';
}
void init()
{
    dx['U'] = -1; dy['U'] = 0;
    dx['D'] = 1; dy['D'] = 0;
    dx['L'] = 0; dy['L'] = -1;
    dx['R'] = 0; dy['R'] = 1;
}
int find_character(int n,int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(real_box[i][j] == 'W')
                return m*i + j;
        }
    }
    return -1;
}
void build_real_box(int n,int m)
{
    memset(real_box,0,sizeof(char)*100*100);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j] == '#')
                real_box[i][j] = '#';
            else if(str[i][j] == 'B' || str[i][j] == 'b')
                real_box[i][j] = 'B';
            else if(str[i][j] == 'W' || str[i][j] == 'w')
                real_box[i][j] = 'W';
            else
                real_box[i][j] = '.';
        }
    }
}
void build_real_map(int n,int m)
{
    memset(real_map,0,sizeof(char)*100*100);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(str[i][j] == '#')
                real_map[i][j] = '#';
            else if(str[i][j] == 'W' || str[i][j] == 'B' || str[i][j] == '+')
                real_map[i][j] = '+';
            else
                real_map[i][j] = '.';
        }
    }
}
