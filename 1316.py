# 함수부
def f(s: str) -> bool:
    hist = [] # 이전 글자를 담을 리스트
    last = s[0]
    hist.append(last)

    for i in s[1:]:
        # == 가장 최근에 넣은 글자가 이번 글자와 같다면
        if i == last:
            hist.append(i)

        # != 가장 최근에 넣은 글자가 이번 글자와 같지 않다면
        else:
            if i not in hist : hist.append(i) # hist에 없는 새로운 글자라면 hist에 기록
            else : return False

        last = i

    return True

# 입력부와 변수선언
n = int(input())
data = []
for i in range(n):
    data.append(input())

# 연산
cnt = 0

for i in range(n):
    if f(data[i]) : cnt += 1

# 출력
print(cnt)