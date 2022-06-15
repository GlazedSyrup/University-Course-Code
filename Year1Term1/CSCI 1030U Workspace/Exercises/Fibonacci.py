# Fib n =   {n, if n == 0 or n == 1
#           {Fib(n-1) + Fib(n-2), if n > 1

def fib(n):
    #base case
    if n <= 1:
        return n

    #recursive case
    return fib(n - 1) + fib(n - 2)

print(fib(0))
print(fib(1))
print(fib(2))
print(fib(3))
print(fib(4))
print(fib(5))
#print(fib(12))