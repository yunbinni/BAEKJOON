# 함수부
def f(n):
    return n + sum([int(i) for i in str(n)])

# 연산
dList = [f(i) for i in range(1, 10001)]

# 출력부
print("\n".join([str(i) for i in range(1, 10001) if i not in dList]))