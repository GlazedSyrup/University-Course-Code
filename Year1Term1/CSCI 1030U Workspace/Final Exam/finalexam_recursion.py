def find_minimum(values):
    try:
        values[0]
    except 'InvalidArgumentError':
        print('List is empty')
    if len(values) == 1:
        return values[0]
    elif values[0] < values[-1]:
        return find_minimum(values[:-1])
    else:
        return find_minimum(values[1:])


'''
values = [1,12,-7,-2,9]
minimum = find_minimum(values)
print(minimum)
# minimum should be -7


measurements = [10.3, -3.05, 5.03, -102.0, 71.4, -1.25, 99.7, -32.9]
minimum = find_minimum(measurements)
print(minimum)
# output: -102.0
'''

with open('data.txt', 'r') as input_file:
    values = []
    for i in input_file:
        values.append(float(i))
minimum = find_minimum(values)
print(minimum)