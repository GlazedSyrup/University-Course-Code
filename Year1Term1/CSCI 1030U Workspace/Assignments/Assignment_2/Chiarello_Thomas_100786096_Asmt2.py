#Part 1:

class Stack:
    def __init__(self):
        self.stack = []
    
    def __str__(self):
        output = '[ '
        if not self.stack:
            output += ']'
            return output
        else:
            for i in self.stack:
                if i == self.stack[0]:
                    output += ''
                output+=f'{str(i)} '
            output += ']'
        return output

    def top(self):
        if (not self.is_empty()):
            return self.stack[-1]
        else:
            return False

    def pop(self):
        return self.stack.pop()

    def push(self, object):
        self.stack.append(object)
        return stack.top()

    def is_empty(self):
        if (len(self.stack) > 0):
            return False
        else:
            return True



stack = Stack()
print('is_empty():', stack.is_empty())
print('empty:', stack)
stack.push(1)
print('after push(1):', stack)
print('is_empty():', stack.is_empty())
stack.push(10)
print('after push(10):', stack)
print('pop():', stack.pop())
print('after pop():', stack)
stack.push(2)
print('after push(2):', stack)
stack.push(3)
print('after push(3):', stack)
stack.push(4)
print('after push(4):', stack)
print('pop():', stack.pop())
print('after pop():', stack)
print('pop():', stack.pop())
print('after pop():', stack)
print('pop():', stack.pop())
print('after pop():', stack)
print('pop():', stack.pop())
print('after pop():', stack)
print('is_empty():', stack.is_empty())



#Part 2:

def is_palindrome(sentence):
    n = len(sentence)
    normal = []
    reversed = []
    for i in sentence:
        normal.append(i)
    for i in sentence[::-1]:
        reversed.append(i)
    #split both stacks
    if n%2 == 1:
        for i in range(int(n/2)+1):
            normal.pop()
            reversed.pop()
    else:
        for i in range(int(n/2)):
            normal.pop()
            reversed.pop()
    #start checking for palindrome
    for i in range(len(normal)):
        if normal.pop() != reversed.pop():
            return False
    return True
    


print(f'is_palindrome("level"): {is_palindrome("level")}')
print(f'is_palindrome("lever"): {is_palindrome("lever")}')
print(f'is_palindrome("definitelynotapalindrome"): {is_palindrome("definitelynotapalindrome")}')
print(f'is_palindrome("ablewasiereisawelba"): {is_palindrome("ablewasiereisawelba")}')
print(f'is_palindrome("ablewasiereisawelbar"): {is_palindrome("ablewasiereisawelbar")}')



#Part 3:

def calculate_rpn(opertation):
    number = ''
    result = []
    last_oper = ''
    for i in range(len(opertation)):
        token = opertation[i]
        if token in ('+', '-', '*', '/'):
            last_oper = i
            num2 = result.pop()
            num1 = result.pop()
            if(token == '+'):
                result.append(num1 + num2)
            elif(token == '-'):
                result.append(num1 - num2)
            elif(token == '*'):
                result.append(num1 * num2)
            elif(token == '/'):
                result.append(num1 / num2)
        elif token == '0' or token == '1' or token == '2' or token == '3' or token == '4' or token == '5' or token == '6' or token == '7' or token == '8' or token == '9':
            number += token
        elif (token == ' '):
            if last_oper != i-1:
                result.append(int(number))
                number = ''
    return int(result[0])



print(f"calculate_rpn('7 2 /'): {calculate_rpn('7 2 /')}")
print(f"calculate_rpn('8 4 * 7 2 / + 4 1 + -'): {calculate_rpn('8 4 * 7 2 / + 4 1 + -')}")