def task2(n):
    if n == 0:
        return
    else:
        print(n, end=" ")
        task2(n - 1)

a = int(input())
task2(a)

# time complexity - O(n)
# space complexity - O(1)