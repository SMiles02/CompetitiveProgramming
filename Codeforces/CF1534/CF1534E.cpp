#include <bits/stdc++.h>
using namespace std;

int ans, t, d[505];
vector<int> v;
deque<int> on, off;

void query()
{
    cout<<"?";
    t=0;
    for (int i : v)
        cout<<" "<<i;
    cout<<endl;
    cin>>t;
    ans^=t;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,cur,x,y;
    cin>>n>>k;
    if (n%2==1&&k%2==0)
    {
        cout<<-1<<endl;
        return 0;
    }
    for (int i=1;i<=n;++i)
    {
        off.push_back(i);
        d[i]=1e9;
    }
    queue<int> q;
    q.push(0);
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i=0;i<=k;++i)
        {
            y=x+k-i*2;
            if (i<=x&&y<=n&&x+k-i<=n&&d[x]+1<d[y])
            {
                q.push(y);
                d[y]=d[x]+1;
            }
        }
    }
    stack<int> s;
    cur=n;
    while (cur!=0)
    {
        s.push(cur);
        for (int i=0;i<=k;++i)
        {
            x=cur+i*2-k;
            if (i<=x&&x+k-i<=n&&d[x]+1==d[cur])
            {
                cur=x;
                break;
            }
        }
    }
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i=0;i<=k;++i)
            if (x==cur+k-i*2)
            {
                v.clear();
                for (int j=0;j<i;++j)
                {
                    v.push_back(on.back());
                    off.push_front(on.back());
                    on.pop_back();
                }
                for (int j=0;j<k-i;++j)
                {
                    v.push_back(off.back());
                    on.push_front(off.back());
                    off.pop_back();
                }
                query();
                break;
            }
        cur=x;
    }
    cout<<"! "<<ans<<endl;
    return 0;
}