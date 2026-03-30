def task9(n):
    if n == 0:
        return 0
    elif n == 1:
        return 1
    else:
        return task9(n - 1) + task9(n - 2)

a = int(input())
print(task9(a))

# time complexity - O(n)
# space complexity - O(1)