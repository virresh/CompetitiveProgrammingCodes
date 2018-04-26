#!/usr/bin/env python

from random import randint as randi 

t = 100

print(t)
for i in range(0,t):
	num = randi(3,1e5)
	print(num)
	for j in range(0,num):
		x = randi(0,1e9)
		print(x,end=" ")
	print("")
