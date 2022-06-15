import re


def recognize_variable(value):
        if(1 == len(re.findall(r"^([a-z]*)$", value))):
            return True
        elif(1 == len(re.findall(r"^((\w?_{1})([a-z]*))", value))):
            return False
        elif(1 == len(re.findall(r"(([a-z]*)(\w?_{1}))$", value))):
            return False
        elif(1 == len(re.findall(r"^(([a-z]*)(\w?_{1})([a-z]*))$", value))):
            return True
        elif(1 == len(re.findall(r"^(([a-z]*)(((\w?_{1})([a-z]*)){2}))$", value))):
            return True
        else:
            return False





str1 = 'abc'
print(f'recognize({str1}) =>', recognize_variable(str1))

str2 = 'abc_def'
print(f'recognize({str2}) =>', recognize_variable(str2))

str3 = 'abc_def_ghi'
print(f'recognize({str3}) =>', recognize_variable(str3))

str4 = '_abc'
print(f'recognize({str4}) =>', recognize_variable(str4))

str5 = 'abc_'
print(f'recognize({str5}) =>', recognize_variable(str5))

str6 = 'abc def'
print(f'recognize({str6}) =>', recognize_variable(str6))

'''
expected output:

recognize(abc) => True
recognize(abc_def) => True
recognize(abc_def_ghi) => True
recognize(_abc) => False
recognize(abc_) => False
recognize(abc def) => False
'''