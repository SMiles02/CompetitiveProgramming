#include <bits/stdc++.h>
using namespace std;

    int length[100005];
    int Par[100005];
    vector<int> Child[100005];

    int dfs (int a) {
        int b=1;
        for(auto w : Child[a]) {
            dfs(w);
            b = max(b, dfs(w)+1);
        }
        length[a] = b;
        return b;
    }






int main () {
    int n,a;
    cin >> n;


    int Par[n+1];
    vector<int> Child[n+1];
    for(int i=2; i<=n; ++i) {
        cin >> a;
        Par[i]=a;
        Child[a].push_back(i);
    }

    for(int i=n; i>0; --i) {cout << dfs(i) << " ";}
}