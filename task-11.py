def task11(arr):
    if len(arr) == 0:
        return 0
    else:
        return arr[0] + task11(arr[1:])


a = list(map(int, input().split()))
print(task11(a))