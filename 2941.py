# 함수부
def f(s: str) -> int:
    croatia = ['c=', 'c-', 'dz=', 'd-', 'lj', 'nj', 's=', 'z=']

    cnt = 0 # 크로아티아 알파벳을 카운트할 변수

    for i in croatia:
        cnt += s.count(i)
        s = s.replace(i, ' ') # 크로아티아 알파벳을 제거한 후 다시 결합 (공백을 주지 않는다면, 대체된 자리의 앞뒤가 다시 결합되어 알파벳으로 판별할 수 있음)

    s = s.replace(' ', '') # 공백제거

    return len(s) + cnt

# 입력부
s = input()

# 출력부
print(f(s))