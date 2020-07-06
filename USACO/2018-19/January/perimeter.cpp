#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int maxArea=0,maxPeri=0,curArea=0,curPeri=0;
int n;
string s[1000];
bool done[1000][1000];

void dfs(int x, int y)
{
    ++curArea;
    done[x][y]=1;
    int score=0;
    if (x>0)
    {
        if (s[x-1][y]=='#')
        {
            ++score;
            if (!done[x-1][y])
            {
                dfs(x-1,y);
            }
        }
    }
    if (y>0)
    {
        if (s[x][y-1]=='#')
        {
            ++score;
            if (!done[x][y-1])
            {
                dfs(x,y-1);
            }
        }
    }
    if (x<n-1)
    {
        if (s[x+1][y]=='#')
        {
            ++score;
            if (!done[x+1][y])
            {
                dfs(x+1,y);
            }
        }
    }
    if (y<n-1)
    {
        if (s[x][y+1]=='#')
        {
            ++score;
            if (!done[x][y+1])
            {
                dfs(x,y+1);
            }
        }
    }
    curPeri+=(4-score);
    return;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	ofstream fout ("perimeter.out");
    ifstream fin ("perimeter.in");
    fin>>n;
    for (int i=0;i<n;++i)
    {
        fin>>s[i];
    }
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
        {
            if (s[i][j]=='#'&&!done[i][j])
            {
                curArea=0;curPeri=0;
                dfs(i,j);
                if (curArea>maxArea)
                {
                    maxArea=curArea;
                    maxPeri=curPeri;
                }
                if (curArea==maxArea&&curPeri<maxPeri)
                {
                    maxArea=curArea;
                    maxPeri=curPeri;
                }
            }
        }
    }
    fout<<maxArea<<" "<<maxPeri<<"\n";
	return 0;
}