def merge(b,c):
    d=b+c
    d.sort()
    return d
        
def msort(a):
    if len(a)==1:
        return
    else:
        b=a[0:len(a)/2]
        c=a[len(a)/2:len(a)]
        msort(b)
        msort(c)
        return merge(b,c)
    
y=[5,4,3,6,7,34,12,3,8,3,5,56,7,8,65,1]
print "Sorted array:"
for i in msort(y):
    print i
