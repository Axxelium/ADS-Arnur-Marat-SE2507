def task8(n):
    if n == 0:
        return
    else:
        print(n % 10, end=" ")
        task8(n // 10)

a = int(input())
task8(a)