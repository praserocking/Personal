#Merge Sort.. O(n*log n)
#Function To Merge The Passed Lists--> O(n)
def merge(b,c):
    d=[]
    i,j=0,0
    while i<len(b) and j<len(c):
        if b[i]<c[j]:
            d.append(b[i])
            i+=1
        else:
            d.append(c[j])
            j+=1
    while j<len(c):
        d.append(c[j])
        j+=1
    while i<len(b):
        d.append(b[i])
        i+=1
    return d

#Function To Sort The List  -->O(log n)     
def msort(a):
    if len(a)==1:
        return a
    else:
        b=msort(a[0:len(a)/2])
        c=msort(a[len(a)/2:len(a)])
        return merge(b,c)

#Driver Codes 
y=[4,3,2,1,6,4,8,5,7,10,8,4,3,2,3,4,9]
print y
print "Sorted List:"
print msort(y)
