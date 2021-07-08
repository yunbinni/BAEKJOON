# 함수부
def f(a: int, b: int) -> str:
    while a != 0 and b != 0:
        if a < b and b % a == 0 : return 'factor'
        elif a > b and a % b == 0 : return 'multiple'
        else : return 'neither'

# 입력부와 변수선언
res = []
while True:
    a, b = list(map(int, input().split()))

    if a == 0 and b == 0 : break
    else:
        res.append(f(a, b))

# 출력부
for i in res:
    print(i)