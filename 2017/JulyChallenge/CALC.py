#!/usr/bin/env python
import math
t = int(input(""))
while(t>0):
	t = t-1
	p = input("").split(' ')
	n = int(p[0])
	b = int(p[1])
	mid = int(math.ceil( math.floor(n/b) /2.0 ))
	ans = mid * (n - b* mid)
	print(ans)