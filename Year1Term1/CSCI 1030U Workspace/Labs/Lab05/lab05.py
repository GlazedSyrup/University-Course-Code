import re


def validate_domain(value):
    if(1 == len(re.findall(r"\w?.com$", value))):
        return True
    elif(1 == len(re.findall(r"\w?.ca$", value))):
        return True
    elif(1 == len(re.findall(r"\w?.org$", value))):
        return True
    else:
        return False


assert validate_domain('google.ca') == True
assert validate_domain('smile.amazon.com') == True
assert validate_domain('unicef.org') == True
assert validate_domain('google.uk') == False


def validate_phone(value):
    if(1 == len(re.findall(r"^(([0-9]{3})(\w?-)([0-9]{4})?)$", value))):
        return True
    elif(1 == len(re.findall(r"^(([0-9]{3})(\w?-{1})([0-9]{3})(\w?-{1})([0-9]{4})?)$", value))):
        return True
    elif(1 == len(re.findall(r"^((\w?\({1})([0-9]{3})(\w?\){1})([0-9]{3})(\w?-{1})([0-9]{4})?)$", value))):
        return True
    else:
        return False


assert validate_phone('721-8668') == True
assert validate_phone('905-721-8668') == True
assert validate_phone('(123)456-8668') == True
assert validate_phone('1234568668') == False


def match_lang(value):
    if(1 == len(re.findall(r"^((\w*a)(\w*b)(\w*c))$", value))):
        lenTest = re.findall(r"^((\w*a)(\w*b)(\w*c))$", value)
    elif(1 == len(re.findall(r"^((\w*b)(\w*c))$", value))):
        lenTest = re.findall(r"^((\w*b)(\w*c))$", value)
    elif(1 == len(re.findall(r"^((\w*a)(\w*c))$", value))):
        lenTest = re.findall(r"^((\w*a)(\w*c))$", value)
    elif(1 == len(re.findall(r"^((\w*c))$", value))):
        lenTest = re.findall(r"^((\w*c))$", value)
    else:
        return False


    if(re.findall(r"^(\w+c)$", (lenTest[0])[1])):
        if(0 == len((lenTest[0])[1])%3):
            return True
        else:
            return False

    elif(re.findall(r"(\w+c)$", (lenTest[0])[2])):
        if(re.findall(r"^(\w+a)", (lenTest[0])[1])):
            if(0 == len((lenTest[0])[1])%2):
                if(0 == len((lenTest[0])[2])%3):
                    return True
                else:
                    return False
            else:
                return False
        elif(re.findall(r"^(\w+b)", (lenTest[0])[1])):
            if(0 == len((lenTest[0])[2])%3):
                return True
            else:
                return False
        else:
            return False
        

    elif(re.findall(r"(\w+c)$", (lenTest[0])[3])):
        if(0 == len((lenTest[0])[1])%2):
            if(0 == len((lenTest[0])[3])%3):
                return True
            else:
                return False
        else:
            return False

    else:
        return False


assert match_lang('abbcc') == False
assert match_lang('bbbcccccc') == True
assert match_lang('aaaaccc') == True
assert match_lang('aabbbbbcccccc') == True


def trim_spaces(value):
    stepOne = re.sub(r"^(\s+)", "", value)
    stepTwo = re.sub(r"(\s+)$", "", stepOne)
    return re.sub(r"\s+", " ", stepTwo)


assert trim_spaces(' bbb ccc') == 'bbb ccc'
assert trim_spaces('bbb ccc   ') == 'bbb ccc'
assert trim_spaces('bbb   ccc') == 'bbb ccc'
assert trim_spaces('  bbb   ccc ') == 'bbb ccc'
