#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

vector<pair<int,int>> v;

float area(int x1, int y1, int x2, int y2, int x3, int y3) 
{ 
   return abs((x1*(y2-y3) + x2*(y3-y1)+ x3*(y1-y2))/2.0); 
}

bool isInside(int x1, int y1, int x2, int y2, int x3, int y3, int x, int y) 
{    
   /* Calculate area of triangle ABC */
   float A = area (x1, y1, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PBC */   
   float A1 = area (x, y, x2, y2, x3, y3); 
  
   /* Calculate area of triangle PAC */   
   float A2 = area (x1, y1, x, y, x3, y3); 
  
   /* Calculate area of triangle PAB */    
   float A3 = area (x1, y1, x2, y2, x, y); 
    
   /* Check if sum of A1, A2 and A3 is same as A */ 
   return (A == A1 + A2 + A3); 
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,ans,a,b;
    int works;
    cin>>n;
    ans=(n*(n-1)*(n-2)*(n-3))/(24);
    for (int i=0;i<n;++i)
    {
        cin>>a>>b;
        v.push_back({a,b});
    }
    for (int c=0;c<n;++c)
    {
        for (int d=c+1;d<n;++d)
        {
            for (int e=d+1;e<n;++e)
            {
                for (int f=e+1;f<n;++f)
                {
                    works=0;
                    for (int x=0;x<c;++x)
                    {
                        if (isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[e].first,v[e].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[f].first,v[f].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[f].first,v[f].second,v[e].first,v[e].second,v[x].first,v[x].second))
                        {
                            works=1;
                            break;
                        }
                    }
                    if (works)
                    {
                        break;
                    }
                    for (int x=c+1;x<d;++x)
                    {
                        if (isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[e].first,v[e].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[f].first,v[f].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[f].first,v[f].second,v[e].first,v[e].second,v[x].first,v[x].second))
                        {
                            works=1;
                            break;
                        }
                    }
                    if (works)
                    {
                        break;
                    }
                    for (int x=d+1;x<e;++x)
                    {
                        if (isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[e].first,v[e].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[f].first,v[f].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[f].first,v[f].second,v[e].first,v[e].second,v[x].first,v[x].second))
                        {
                            works=1;
                            break;
                        }
                    }
                    if (works)
                    {
                        break;
                    }
                    for (int x=e+1;x<f;++x)
                    {
                        if (isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[e].first,v[e].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[f].first,v[f].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[f].first,v[f].second,v[e].first,v[e].second,v[x].first,v[x].second))
                        {
                            works=1;
                            break;
                        }
                    }
                    if (works)
                    {
                        break;
                    }
                    for (int x=f+1;x<n;++x)
                    {
                        if (isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[e].first,v[e].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[d].first,v[d].second,v[f].first,v[f].second,v[x].first,v[x].second)||isInside(v[c].first,v[c].second,v[f].first,v[f].second,v[e].first,v[e].second,v[x].first,v[x].second))
                        {
                            works=1;
                            break;
                        }
                    }
                    if (works)
                    {
                        break;
                    }
                    else
                    {
                        --ans;
                    }
                }
            }
        }
    }
    cout<<ans;
    return 0;
}