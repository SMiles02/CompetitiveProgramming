#include <bits/stdc++.h> 
using namespace std; 
  
const int N = 20, M = 101; 
int n, m, w[M]; 
vector<int> a[N]; 
bitset<M> likes[N]; 
bitset<N> dp[1 << N]; 
bitset<(1 << N)> works; 
  
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int k, x; 
    cin >> m >> n; 
    for (int i = 1; i <= m; ++i) 
        cin >> w[i]; 
    for (int i = 0; i < n; ++i) { 
        k = 2; 
        while (k--) { 
            cin >> x; 
            likes[i][x] = 1; 
            a[i].push_back(x); 
        } 
    } 
    works[0] = 1; 
    for (int i = 1; i < (1 << n); ++i) { 
        for (int j = 0; j < n; ++j) 
            if ((i & (1 << j)) && works[i ^ (1 << j)]) { 
                bool ok = false; 
                for (int l : a[j]) { 
                    x = 0; 
                    for (int o = 0; o < n; ++o) 
                        if ((i & (1 << o)) && o != j) 
                            x += likes[o][l]; 
                    if (x < w[l]) { 
                        ok = true; 
                        break; 
                    } 
                } 
                if (ok) { 
                    dp[i][j] = 1; 
                    works[i] = 1; 
                } 
            } 
    } 
    if (works[(1 << n) - 1]) { 
        cout << "YES\n"; 
        // x = (1 << n) - 1; 
        // vector<int> ans; 
        // while (x) 
        //     for (int i = 0; i < n; ++i) 
        //         if ((x & (1 << i)) && dp[x][i]) { 
        //             ans.push_back(i); 
        //             x ^= (1 << i); 
        //             break; 
        //         } 
        // while (!ans.empty()) { 
        //     cout << ans.back() + 1 << " "; 
        //     ans.pop_back(); 
        // } 
    } 
    else
        cout << "NO\n"; 
    return 0; 
}