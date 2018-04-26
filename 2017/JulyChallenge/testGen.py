#!/usr/bin/env python

import random

print("10")
for i in range(1,11):
    for k in range(1,100001):
        t = random.randint(1,3)
        if(t==1):
            print("=",end='')
        elif(t==2):
            print("<",end='')
        else :
            print(">",end='')
    print("")
