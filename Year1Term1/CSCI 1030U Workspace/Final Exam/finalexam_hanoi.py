def towers_of_hanoi(n, start, end, temp, c = 0): 
    if n < 1: 
        return

    towers_of_hanoi(n - 1, start, temp, end) 
    print('Move 1 ring from', start, 'to', end)   # count this line only 
    count = c+1
    towers_of_hanoi(n - 1, temp, end, start, count)

towers_of_hanoi(5, 1, 1, 1)
'''
best guess:  2^n - 1
n   prints
----------
1   1
2   3
3   7
4   15
5   31
6   63
'''