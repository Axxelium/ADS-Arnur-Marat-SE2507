def task16(arr, target, low, high):
    if low > high:
        return "Not found"
    mid = (low + high) // 2
    if arr[mid] == target:
        return f"Element found at index {mid}"
    elif arr[mid] > target:
        return task16(arr, target, low, mid - 1)
    else:
        return task16(arr, target, mid + 1, high)

a = list(map(int, input().split()))
t = int(input())
print(task16(a, t, 0, len(a) - 1))

# time complexity - O(log n)
# space complexity - O(1)