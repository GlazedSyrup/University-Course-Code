import numpy as np

def simulate_game():
    simuationTime = 1000
    totalProbability = 0
    while simuationTime >0:
        rolls_remaining = 100
        totalTimesAchieved = 0
        threeConsecutive = [0, 0, 0,]

        simuationTime -= 1
        while rolls_remaining >0:
            rolls_remaining -= 1
            roll = np.random.randint(1,7)
            threeConsecutive.append(roll)
            threeConsecutive.pop(0)

            if threeConsecutive[0] == threeConsecutive[1] == threeConsecutive[2]:
                totalTimesAchieved +=1
                threeConsecutive = [0, 0, 0]
        
        totalProbability += (totalTimesAchieved/100)

        
    return totalProbability/1000






print(simulate_game())

'''
expected output (this could differ, depending on the random values):
0.312
'''