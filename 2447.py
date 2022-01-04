def f(r:int, c:int, n:int) -> None:
    if (r//n) % 3 == 1 and (c//n) % 3 == 1:
        print(" ", end='')
    elif n < 3:
        print("*", end='')
    else:
        f(r, c, n/3)

if __name__ == "__main__":
    n = int(input())

    for i in range(n):
        for j in range(n):
            f(i, j, n)
        print()