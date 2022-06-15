import re

# + == 1 or more
# ? == 0 or 1 (optional)
# {5} == exactly 5 occurrences
# {2,5} == between 2 or 5 occurrences
# [a-z] == matches any one of these characters
# [^a-z] == matches an character except one of these characters
# \s == matches any whitespace character (space, tab, newline)
# \w == matches any word character, identical to [a-zA-Z0-9_]
#
#
# . == any character we want
#
#
#












re1 = re.compile('a*') #Star means 0 or more
match = re1.match('aaaaa')
if match:
    print('1. It matches!')

re2 = re.compile('(a*)|(b*)') #
match = re2.match('abb')
if match:
    print('2. It matches!')
    print('Match string:', match.group())

re3 = re.compile('^a*$') # begining of the string - 0 or more - end of the string
match = re3.match('aaa')
if match:
    print('3. It matches!')
    print('Match string:', match.group())

re4 = re.compile('[^a-z]+') # 
match = re4.match('abb')
if match:
    print('4. It matches!')
    print('Match string:', match.group())

re5 = re.compile('bba+') #
match = re5.match('bbbbbaaa')
if match:
    print('5. It matches!')
    print('Match string:', match.group())

re6 = re.compile('^bba+$')
match = re6.match('bbaaa')
if match:
    print('6. It matches!')
    print('Match string:', match.group())

# binary number with either 4 digits or 8 digits
#re3 = re.compile('^(([01]{4})|([01]{8}))$')
re7 = re.compile('^(([01]{4})([01]{4})?)$')
match = re7.match('00110')
if match:
    print('binary. It matches!')
    print('Match string:', match.group())
else:
    print('No match')

# recognize first name, middle name, last name (e.g. Barb Elan Jones)
re8 = re.compile('^([A-Z][a-z]+\s){2}([A-Z][a-z]+)$')
match = re8.match('James Earl Jones')
if match:
    print('name. It matches!')
    print('Match string:', match.group())
else:
    print('No match')