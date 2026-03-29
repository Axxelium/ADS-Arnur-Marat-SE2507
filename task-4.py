def task4(n):
    if n == 0:
        return 1
    else:
        return n * task4(n - 1)

a = int(input())
print(task4(a))