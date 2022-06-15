def multiply_all_pairs(l1, l2):
    pairs = []
    for i in l1:
        for ii in l2:
            pairs.append(i*ii)
    return pairs


list1 = [1,2,3]
list2 = [4,5,6]
print(multiply_all_pairs(list1, list2))
# output: [4, 5, 6, 8, 10, 12, 12, 15, 18] 