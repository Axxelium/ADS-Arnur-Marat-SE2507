def task5(n):
    if n == 0:
        return 0
    else:
        return n % 10 + task5(n // 10)

a = int(input())
print(task5(a))