def task10(s):
    if len(s) <= 1:
        return "Palindrome"
    elif s[0] != s[-1]:
        return "Not palindrome"
    else:
        return task10(s[1:-1])

word = input()
print(task10(word))