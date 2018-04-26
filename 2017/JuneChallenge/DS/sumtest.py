from decimal import *
getcontext().prec = 4002
on = int(input())
l = []
sign = []
def S(A,n):
	while(1):
		if(n==0):
			l.append(0)
			break;
		if(n==1):
			l.append(int(A))
			break;

		if(A>=2):
			k = int(A-1)
			B = A-k
			l.append(k*int(n*(n+1))//2)
			sign.append(1)
			A = B
		elif(1<=A<2):
			B = 1 + 1/(A-1)
			n2 = int((A-1)*n)
			sign.append(-1)
			l.append(int((n+n2)*(n+n2+1))// 2)
			A = B
			n = n2
	res = 0
	for i in l[len(sign):]:
		res = res + i
	for i in range(len(sign)-1,-1,-1):
		if(sign[i]>0):
			res = l[i] + res
		else:
			res = l[i] - res
	return res

ans = S(Decimal('1').exp(),on)

print (ans)

# for i in l:
# 	print (i,end=' ')

# print("")

# for i in sign:
# 	print (i,end=' ')

# print("")