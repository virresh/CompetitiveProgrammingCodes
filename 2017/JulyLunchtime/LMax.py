#!/usr/bin/env python

x = int(input())
while(x>0):
	x-=1
	y = input()
	z = list(map(int,y.split(' ')))
	sortL = sorted(z)
	n = len(z)-1
	# print (n,sortL[n-1])
	if(int(sortL[n])==n):
		print (sortL[n-1])
	else:
		print (sortL[n])