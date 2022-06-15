import re


def match_lang(value):
    if(1 == len(re.findall(r"^(([0-9]*)((\s{1})([a-zA-Z]+))+)$", value))):
        return True

print(match_lang("2000 Simcoe Road North"))
print(match_lang("290 Bremner Blvd"))
print(match_lang("123 Apple"))
class Queue:
    def __init__(self, ):
        self.queue = []
    def enqueue(self, n): #Adds an element to the back of the queue
        self.queue.append(n)
    def front(self): #Returns the front element
        return self.queue[0]
    def dequeue(self): #Removes the front element
        return self.queue.pop(0)
    def is_empty(self): #Returns True if the queue is empty
        if not self.queue:
            return True
        else:
            return False
    def __str__(self): #Returns a string representation of the queue
        output = '[ '
        if not self.queue:
            output += ']'
            return output
        else:
            for i in self.queue:
                if i == self.queue[0]:
                    output += ''
                output+=f'{str(i)} '
            output += ']'
        return output

queue = Queue()
print('is_empty():', queue.is_empty())
print('empty:', queue)
queue.enqueue(1)
print('after enqueue(10):', queue)
queue.enqueue(2)
print('after enqueue(10):', queue)
queue.enqueue(3)
print('after enqueue(10):', queue)
queue.enqueue("A")
print('after enqueue(10):', queue)
print('dequeue():', queue.dequeue())
print('after dequeue():', queue)
print('dequeue():', queue.dequeue())
print('after dequeue():', queue)
queue.enqueue("B")
print('after enqueue(2):', queue)
queue.enqueue("C")
print('after enqueue(3):', queue)
queue.enqueue("D")
print('after enqueue(4):', queue)
print('dequeue():', queue.dequeue())
print('after dequeue():', queue)