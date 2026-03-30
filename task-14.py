def task14(arr, target):
    if len(arr) == 0:
        return "Not found"
    elif arr[0] == target:
        return "Found"
    else:
        return task14(arr[1:], target)

a = list(map(int, input().split()))
t = int(input())
print(task14(a, t))