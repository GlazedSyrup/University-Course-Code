
def has_no_repeated_letter(string):
    if not string:
        return True
    else:
        characters = []
        for c in string:
            characters.append(c)
        if string[0] in characters[1:]:
            return False
        return has_no_repeated_letter(string[1:])
    return True


def get_longest_matching_substring(string, check_match):
    longestLength = 0
    longestSentence = ""
    for l in range(len(string)):
        for f in range(len(string)):
            if check_match(string[f:l]):
                if longestLength < len(string[f:l]):
                    longestLength = len(string[f:l])
                    longestSentence = string[f:l]
    return longestSentence


print('ablewasiereisawelba:', has_no_repeated_letter('ablewasiereisawelba'))
print('abcd:', has_no_repeated_letter('abcd'))
print('longest with no repeated letter:', get_longest_matching_substring('i saw abba, but ablewasiereisawelba by the racecar', has_no_repeated_letter))
