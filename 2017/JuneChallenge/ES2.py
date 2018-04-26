e_continuedFrac = [2,1]
i=0
seq=2
while(i<4003):
	#fetch the first 10000 sequences of continued fraction for e
	if(i%3==0):
		e_continuedFrac.append(seq)
		seq+=2
	else:
		e_continuedFrac.append(1)
	i+=1

#variable initialisations
n0 = 2
d0 = 1
n1 = 3
d1 = 1

def calcE():
	# calculate a rational approximation for e of around 10000 digits
	global n0,n1,d0,d1
	for x in e_continuedFrac[2:]:
		n = x * n1 + n0 
		d = x * d1 + d0

		n0 = n1
		n1 = n
		
		d0 = d1
		d1 = d

calcE()

n = int(input())

t = 1
p = n1
q = d1
s = 0
z = 1

while(q>0 and n>0):
	t = p//q
	s = s+ z * t * ((n * (n+1))//2)
	p = p - q * t

	t = n//q
	s = s + z * p * t * (n+1) - ( z * t * (p *q *t + p + q -1)//2 )
	n = n - q * t

	t = (n * p)//q
	s = s+ z*t*n
	n = t
	(p,q)= (q,p)
	z = -z

print(s)
