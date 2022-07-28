for t in range(int(input())):
	n = int(input())
	l = 1
	r = n
	while l < r:
		m = l + (r - l) // 2
		print("?", l, m, flush=True)
		if (sum(l <= i <= m for i in [int(x) for x in input().split()]) % 2):
			r = m
		else:
			l = m + 1
	print("!", l, flush=True)