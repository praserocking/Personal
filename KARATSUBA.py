def karatsuba(x,y):
    n=max(len(x),len(y))
    if(n<=3):
        return int(x)*int(y)
    else:
        a=x[0:len(x)/2];
        b=x[len(x)/2:len(x)];
        c=y[0:len(y)/2];
        d=y[len(y)/2:len(y)];
        p=karatsuba(a,c)
        q=karatsuba(b,d)
        r=karatsuba(a,d)+karatsuba(b,c)
        if n%2==0:
            m=n/2
        else:
            m=n/2
        return (10**n)*p+(10**m)*r+q

print karatsuba("1234","5678")    
 
 
 #has bugs will debug it soon!! 
