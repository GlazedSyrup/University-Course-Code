def reverse_words(sentence):
#Initialize variables
    count = 0
    word = ""
    senList = []
    revWords = ''
#put the words in a stack
    for i in sentence:
        if i == ' ':
            senList.append(word)
            word = ""
        else:
            word += i
        count += 1
    senList.append(word)
#reverse the words using pop
    for i in range(len(senList)):
        revWords += senList.pop() + ' '

    return revWords



sentence1 = 'there can be only one'
print(f'reverse_words({sentence1}) =>', reverse_words(sentence1))

sentence2 = 'nothing'
print(f'reverse_words({sentence2}) =>', reverse_words(sentence2))

'''
expected output:

reverse_words(there can be only one) =>  one only be can there
reverse_words(nothing) =>  nothing
'''
