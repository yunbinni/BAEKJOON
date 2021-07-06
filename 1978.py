# 함수부
def prime(n):
    if n == 1 : return False
    elif n == 2 : return True
    else:
        for i in range(2, n):
            if n % i == 0 : return False
        return True

# 입력부와 변수선언
n = int(input())
data = list(map(int, input().split()))
res = 0

# 연산
for i in data:
    if prime(i) : res += 1

# 출력
print(res)