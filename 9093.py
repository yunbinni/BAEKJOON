n=int(input())

while n:
    n-=1
    s = list(input().split())
    for w in s:
        print(w[::-1], end=' ')
    print()