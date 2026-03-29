def task7(n):
    if n == 0:
        return 0
    else:
        return 1 + task7(n // 10)

a = int(input())
print(task7(a))