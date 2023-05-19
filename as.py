t = int(input())

for _ in range(t):
    n, k = map(int, input().split())
    a = list(map(int, input().split()))
    a.sort()

    if k >= (n - 3):
        print(sum(a[n-3:]))
    else:
        sum_val = 0
        for i in range(0, k * 2, 2):
            sum_val += a[i]
        print(sum_val)
