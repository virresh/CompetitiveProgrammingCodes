t = int(input(""))
while(t > 0):
    t = t-1
    x = input("")
    y = x.split(" ")
    if(len(y)==1):
        st = y[0][0:1].upper() + y[0][1:].lower()
    elif (len(y) == 2):
        st = y[0][0].upper() + '. ' + y[1][0:1].upper() + y[1][1:].lower()
    elif (len(y)==3):
        st = y[0][0].upper()+'. '+y[1][0].upper() + '. ' + y[2][0].upper() + y[2][1:].lower()
    print (st)
