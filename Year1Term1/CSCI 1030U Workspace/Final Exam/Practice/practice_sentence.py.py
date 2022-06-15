def getWordSize(word):
    count = 0
    len = 0
    for i in word:
        len += 1
    if len != 0:
        return 1 + getWordSize(word[:-1])
    elif len == 1:
        return 1
    else:
        return 0

def processSentence(sentence, processWord):
    word = ""
    lengths = []
    for i in sentence:
        if i == " ":
            lengths.append(processWord(word))
            word = ""
        else:
            word += i
    lengths.append(processWord(word))
    return lengths

print(getWordSize("OoggaBooga"))
print(processSentence("the quick brown fox jumped over the lazy dog", getWordSize))
