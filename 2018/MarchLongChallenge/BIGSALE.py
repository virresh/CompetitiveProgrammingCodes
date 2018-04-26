#!/usr/bin/env python
t = int(input())
while(t>0):
	t-=1
	n = int(input())
	ans = 0.0
	for i in range(0,n):
		inp = input().split(' ')
		qty = int(inp[0])
		price = float(inp[1])
		x = float(inp[2])
		ans = ans + qty * price * (x * x / 10000.0)
	print(ans)