from math import gcd

for _ in range(1):
	n = 15
	a = [-377831861, 943372732, -910180089, 498576795, -516058682, 154481372, 584231071, 568687327, 365083775, -876040137, -217287261, -76821043, 607885264, 297033905, -332674858]
	g = 0
	for i in range(n - 1):
		g = gcd(g, a[i + 1] - a[i])
	g = max(g, 1)
	a.sort()
	j = n - 1
	res = a[-1]
	while True:
		while j >= 0 and a[j] > res:
			j -= 1
		if j < 0 or a[j] != res:
			break
		res -= g
	print(g, j)
	print(a[-1]-1, (a[-1]-1 in a), res)
	print((a[-1] * (n + 1) - (sum(a) + res)) // g)
	print((a[-1]*n-sum(a))/g)
