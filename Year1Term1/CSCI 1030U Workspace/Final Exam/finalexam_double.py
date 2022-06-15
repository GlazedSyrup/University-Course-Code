
def mymap(op, values):
    newValues = []
    for i in range(len(values)):
        newValues.append(op(values[i]))
    return newValues


values = [1,2,3,4,5]
doubleValues = mymap(lambda x: x * 2, values)
print(doubleValues) # doubleValues should be [2,4,6,8,10]
