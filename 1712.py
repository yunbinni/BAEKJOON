a, b, c = map(int, input().split())

# 비용이 가격보다 크거나 같으면 이익발생 불가
if b >= c:
    print(-1)
else:
    print(a // (c - b) + 1)

"""
A - 고정비
B - 대당 가변비용
C - 가격

총 수입 > 총 비용
c * 판매대수(x) > a + b * 판매대수(x)

(c - b) * x > a
x > a / (c - b)
"""