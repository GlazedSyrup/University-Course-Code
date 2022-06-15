import re # Needed for regexes
# https://regex101.com/ is a good resource for checking your regexes 

# Some common regex patterns:
"""
\w - match any word character (0-9, a-z, A-Z)
\d - match a digit (0-9)
\D - any non-digit character
\s - match any whitespace character
\n - match any newline character

b{3} - exactly 3 of b
b{1,3} - between 1 and 3 of b

(abc) - a capturing group (will match: abc)
[abc] - matches any character in the list (will match: a,b,c)

* - match 0 or many of the previous group
+ - match 1 or many of the previous group
? - match 0 or 1 of the previous group
"""

def has_apple(string):
    exp = "apple" # Matches occurances of "apple"
    # Find a match in the string for the regex in exp
    # The string is converted to lower case so that items such as "Apple" will be found

    # Or:
    # exp = re.compile("apple")
    # return exp.search(string.lower()).group()
    return re.search(exp, string.lower()).group()

def rm_punc(string):
    # A list (denoted by the square brackets) of punctuation characters
    exp = "[\s\(\).!?\\'-]" 
    return re.sub(exp, "", string.lower()) # Replaces the occurances of exp in the string with a "!"

def return_words(string):
    exp = "\w+" # Matches 1 to many of any letter. Ex: "a", "aw", "aws", etc. 
    return re.findall(exp, string) # Get all of the words in the string (returns an array)

print(has_apple("For my examples I commonly use Apples and Oranges."))
print(rm_punc("This string is a test - it will have it's punctuation removed."))
print(return_words("All of these words will be returned individually"))
string = "For my examples I commonly use Apples and Oranges."
print(re.search("apple", string.lower()))


