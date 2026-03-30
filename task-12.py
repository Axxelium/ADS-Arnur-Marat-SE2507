def task12(arr):
    if len(arr) == 1:
        return arr[0]
    else:
        max_rest = task12(arr[1:])
        if arr[0] > max_rest:
            return arr[0]
        else:
            return max_rest

a = list(map(int, input().split()))
print(task12(a))

# time complexity - O(n)
# space complexity -