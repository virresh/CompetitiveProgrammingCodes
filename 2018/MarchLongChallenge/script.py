#!/usr/bin/env python
import random

n = random.randint(2,10)
q = random.randint(2,6)
print(n,q)
for i in range(0,n):
	x = random.randint(0,1000)
	print(x,end=" ")
print("")

for i in range(0,q):
	l = random.randint(1,n-1)
	r = random.randint(l,n)
	print(l,r)