#include <bits/stdc++.h> 
using namespace std; 
  
const int N = 1e6 + 7, MOD = 1e6; 
int a[3000][3000], f[N]; 
  
int main() { 
    ios_base::sync_with_stdio(0); cin.tie(0); 
    int n, minX = 1500, maxX = 1500, minY = 1500, maxY = 1500, curX = 1500, curY = 1500, cur = 0; 
    cin >> n; 
    f[0] = f[1] = 1; 
    a[curX][curY] = 1; 
    for (int i = 2; i < N; ++i) 
        f[i] = (f[i - 1] + f[i - 2]) % MOD; 
    for (int i = 1; i < n; i += 2) { 
        a[curX][++curY] = f[++cur]; 
        for (int j = 0; j < i; ++j) 
            a[--curX][curY] = f[++cur]; 
        for (int j = 0; j < i + 1; ++j) 
            a[curX][--curY] = f[++cur]; 
        for (int j = 0; j < i + 1; ++j) 
            a[++curX][curY] = f[++cur]; 
        for (int j = 0; j < i + 1; ++j) 
            a[curX][++curY] = f[++cur]; 
        --minX; 
        ++maxX; 
        --minY; 
        ++maxY; 
    } 
    for (int i = minX; i <= maxX; ++i) { 
        for (int j = minY; j < maxY; ++j) 
            cout << a[i][j] << ","; 
        cout << a[i][maxY] << "\n"; 
    } 
    return 0; 
}