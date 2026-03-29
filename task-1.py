def task1(n):
    if n == 0:
        return 0
    else:
        task1(n - 1)
        print(n, end=" ")

a = int(input())
task1(a)