#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

string reverse(string str, int len, int l, int r) 
{ 
  
    // Invalid range 
    if (l < 0 || r >= len || l > r) 
        return str; 
  
    // While there are characters to swap 
    while (l < r) { 
  
        // Swap(str[l], str[r]) 
        char c = str[l]; 
        str[l] = str[r]; 
        str[r] = c; 
  
        l++; 
        r--; 
    } 
  
    return str; 
}

void rev(string s, int n, int k)
{
    for (int i=0;i+k-1<n;++i)
    {
        s=reverse(s,n,i,i+k-1);
    }
    cout<<s<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    string s;
    cin>>n;
    cin>>s;
    for (int i=1;i<=n;++i)
    {
        cout<<i<<": ";
        rev(s,n,i);
    }
    return 0;
}