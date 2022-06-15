'''
def get_all_pairs(list1, list2):
    for i in list1:
        for ii in list2:
            print(i, ii)
'''

def get_all_pairs(list1, list2):
    list3 = list1[:]
    var = []
    if len(list1) == 0:
        return [var]
    for i in list2:
        var.append((list3[0], " , '" + i + "'")
    
    list3.remove(list3[0])

    return get_all_pairs(list3, list2) + [var]






list1 = [1,2,3]
list2 = ['a', 'b']
pairs = get_all_pairs(list1, list2)

print(pairs)
# expected output:  [(1, 'a'), (1, 'b'), (2, 'a'), (2, 'b'), (3, 'a'), (3, 'b')]