def task2(n):
    if n == 0:
        return 0
    else:
        print(n, end=" ")
        task2(n - 1)

a = int(input())
task2(a)