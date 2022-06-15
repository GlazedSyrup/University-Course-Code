import re
#Question 6
'''
def match_lang(value):
    if(1 == len(re.findall(r"^((<{1}\w+>{1}){1}(\w*\s*\W*)+(<{1}/{1}\w+>{1}){1})$", value))):
        return True

print(match_lang("<a>hello</a>"))
print(match_lang("<div>one two three</div>"))
print(match_lang("<p>It was the best of times...</p>"))
'''
'''
#Question 7
def match_lang(value):
    if(1 == len(re.findall(r"^(([A-Z]{1}[0-9]{1}){3})$", value))):
        return True

print(match_lang("V5G4X1"))
print(match_lang("M5V3L9"))
print(match_lang("L1H7K4"))
'''