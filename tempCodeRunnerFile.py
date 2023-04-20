# cook your dish here
a = int(input())

for _ in range(a):
    p =int(input())
    ar = list(map(int,input().split()))
    
    right=[]
    left=[]
    
    for i in range(len(ar)-1):
        right.append(abs(ar[i]-ar[i+1]))
    
    for i in range(1,len(ar)):
        left.append(abs(ar[i]-ar[i-1]))
        
    print(min(min(right), min(left)))