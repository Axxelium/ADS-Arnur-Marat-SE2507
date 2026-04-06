def task6(n):
    if n == 0:
        return 0
    else:
        return n % 10 + task6(n // 10)

a = int(input())
print(task6(a))

# time complexity - O(n)
# space complexity - O(n)