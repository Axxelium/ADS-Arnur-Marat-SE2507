def task1(n):
    if n == 0:
        return
    else:
        task1(n - 1)
        print(n, end=" ")

a = int(input())
task1(a)

# time complexity - O(n)
# space complexity - O(1)