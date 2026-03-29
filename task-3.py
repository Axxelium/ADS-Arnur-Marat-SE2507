def task3(n):
    if n == 0:
        return 0
    else:
        return n + task3(n - 1)

a = int(input())
print(task3(a))