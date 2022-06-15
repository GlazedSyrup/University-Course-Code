
def processGame(filename, handler):
    #get contents of the file into a string, pass it through handler
    with open(filename, 'r') as input_file:
        singleLine = ""
        for i in input_file:
            singleLine += str(i)
        handler(singleLine)
def printGame(gameState):
    count = 0
    line = ""
    for i in range(9):
        for ii in range(9):
            line += str(gameState[count])
            line += " "
            count += 1
        print(line)
        line = ""

print(processGame('gamefile.txt', printGame)) 