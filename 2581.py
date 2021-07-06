# 함수부
def prime(n):
    if n == 1 : return False
    elif n == 2 : return True
    else:
        for i in range(2, n):
            if n % i == 0 : return False
        return True

# 입력부와 변수선언
m = int(input())
n = int(input())
res = [] # 소수를 담을 리스트

# 연산
for i in range(m, n + 1):
    if prime(i) : res.append(i)

# 출력
if len(res) == 0:
    print(-1)
else:
    print(sum(res))
    print(min(res))