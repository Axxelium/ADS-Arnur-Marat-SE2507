def task13(arr, target):
    if len(arr) == 0:
        return 0
    else:
        count = 1 if arr[0] == target else 0
        return count + task13(arr[1:], target)

a = list(map(int, input().split()))
t = int(input())
print(task13(a, t))