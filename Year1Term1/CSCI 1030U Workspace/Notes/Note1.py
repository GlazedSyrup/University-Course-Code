'''
def foo(string, index):
    goo = ""
    count = -1
    for i in string:
        count += 1
        if count == index:
            goo += "-"
        else:
            goo += i
    return goo
print(foo("hello world", 9))
'''
def foo(string, index):
    goo = ""
    for i in range(len(string)):
        letter = string[i]
        if i == index:
            goo += "-"
        else:
            goo += letter
    return goo
print(foo("hello world", 9))
