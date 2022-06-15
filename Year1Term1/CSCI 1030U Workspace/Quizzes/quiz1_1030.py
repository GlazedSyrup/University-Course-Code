# Initialization
sentence = 'the quick brown fox jumped over the lazy dog'
word_lengths = []

current_word_length = 0
pos_of_last_space = 0
count = 0

# Main program
for i in sentence:
    if i == ' ':
        word_lengths.append(current_word_length)
        current_word_length = 0
        pos_of_last_space = count
    else:
        current_word_length += 1
    count += 1

word_lengths.append(len(sentence)-(pos_of_last_space+1))

# Output
print(word_lengths)
# expected output:  [3, 5, 5, 3, 6, 4, 3, 4, 3]