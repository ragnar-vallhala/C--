# cook your dish here
a = int(input())

def count(st):
    num=0
    num2=0

    for i in range(len(st)-1):
        if st[i]=='1' and st[i+1]=='0':
            num+=1
        elif st[i]=='0' and st[i+1]=='1':
            num2+=1
    return num , num2


for _ in range(a):

    b = int(input())
    xt = input()

    j,k = count(xt)

    j = max(j,k)

    if j%2==0:
        print("Ramos")
    else:
        print("Zlatan")