def task5(a, b):
    if b == 0:
        return 1
    else:
        return a * task5(a, b - 1)

x = int(input())
y = int(input())
print(task5(x, y))

# time complexity - O(n)
# space complexity - O(n)