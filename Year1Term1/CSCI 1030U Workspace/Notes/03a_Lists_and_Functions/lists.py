names = ['Sandra', 'Kunal', 'Mohammed', 'Wendy', 'Jules']
for name in names:
    print(name)

midterm_grades = [38.5, 56.0, 66.5, 95.0, 72.0, 26.0, 52.0]
total = 0.0
for grade in midterm_grades:
    total += grade
    print('Total for the midterm:', total)
    print('Average for the midterm:', total / len(midterm_grades))

sentence = 'The quick brown fox jumped over the lazy dog'
words = []
current_word = ''
for character in sentence:
    if character == ' ':
        words.insert(0, current_word)
        current_word = ''
    else:
        current_word = current_word + character

words.insert(0, current_word)
print(f'words: {words}')
print('using split:', sentence.split(' '))

words.remove('the')
print(f'words2: {words}')

words.pop()
print(f'words3: {words}')
'''
take inputs
produce outputs
let you reuse your code
can 'call' functions from many places
all code to do that one thing is in one place
'''


def average(values):
    total = 0.0
    for grade in values:
        total += grade
    return total / len(values)

midterm_grades = [38.5, 56.0, 66.5, 95.0, 72.0, 26.0, 52.0]
print('Average: ', average(midterm_grades))

test_values = [0, 5, 10]
print('Average2 ', average(test_values))

one_value = [3]
print('Average3 ', average(one_value))



#coding exercise ceaser cipher
def shift(character, shift_amount):
    alpha = 'abcdefghijklmnopqrstuvwxyz'
    char_index = alpha.index(character)
    new_index = char_index + shift_amount

    if new_index < 0:
        new_index += len(alpha)

    if new_index >= len(alpha):
        new_index -= len(alpha)

    return alpha[new_index]

def caesar_cipher(message, shift_amount):
    ciphertext = ''
    for character in message:
        new_character = shift(character, shift_amount)
        ciphertext += new_character
    return ciphertext

message = 'meetmeatthezoo'
print(f'{message} encrypted using the caesar cipher is:', caesar_cipher(message, 1))

c = 'a'
print(f'{c} shifted is', shift(c, 1))