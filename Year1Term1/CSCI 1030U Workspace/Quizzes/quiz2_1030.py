values = [2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14]
is_prime = []
is_not_prime = False

for i in range(len(values)):
    is_not_prime = False

    for ii in range(2, values[i]):
        if (values[i] % ii == 0):
            is_not_prime = True
            break

    if not(is_not_prime):
        is_prime.append("True")
    else:
        is_prime.append("False")



print(is_prime)
# expected output:  [True, True, False, True, False, True, False, False, False, True, False, True, False]