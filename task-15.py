def task15(arr):
    if len(arr) <= 1:
        return "Sorted"
    elif arr[0] > arr[1]:
        return "Not sorted"
    else:
        return task15(arr[1:])

a = list(map(int, input().split()))
print(task15(a))