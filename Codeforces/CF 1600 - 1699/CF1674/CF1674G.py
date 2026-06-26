n, m = map(int, input().split())
fro = [[] for _ in range(n + 1)]
to = [[] for _ in range(n + 1)]
to_cnt = [0] * (n + 1)
dp = [1] * (n + 1)
topo = []
ans = 0
for _ in range(m):
    x, y = map(int, input().split())
    fro[x].append(y)
    to[y].append(x)
    to_cnt[y] += 1
for i in range(1, n + 1):
    if to_cnt[i] == 0:
        topo.append(i)
while len(topo) > 0:
    x = topo.pop()
    for i in fro[x]:
        to_cnt[i] -= 1
        if to_cnt[i] == 0:
            topo.append(i)
        if len(fro[x]) > 1 and len(to[i]) > 1:
            dp[i] = max(dp[i], dp[x] + 1)
    ans = max(ans, dp[x])
print(ans)