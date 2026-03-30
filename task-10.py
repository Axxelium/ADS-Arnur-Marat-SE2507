def task10(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return task10(n - 1) + task10(n - 2)

a = int(input())
print(task10(a))