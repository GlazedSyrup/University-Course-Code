import numpy as np

class LotterySimulation:
    def __init__(self, ticket_cost = 2, odds_of_winning = 0.0000000300347201, jackpot_value = 40000000, weeks_to_simulate = 520):
        self.ticket_cost = ticket_cost
        self.odds_of_winning = odds_of_winning
        self.jackpot_value = jackpot_value
        self.weeks_to_simulate = weeks_to_simulate
        self.money_spent = 0 
        self.money_won = 0

    def play_lottery(self):
        random_val = np.random.rand()
        if (self.odds_of_winning > random_val):
            return True
        else:
            return False

    def run(self):
        if self.weeks_to_simulate == 0:
            while True:
                self.weeks_to_simulate += 1
                self.money_spent += self.ticket_cost
                if self.play_lottery() == True:
                    self.money_won = self.jackpot_value
                    break
        else:
            for i in range(self.weeks_to_simulate):
                self.money_spent += self.ticket_cost
                if self.play_lottery() == True:
                    self.money_won = self.jackpot_value
                    break

    def print_summary(self): 
        print(f'Money spent:     {self.money_spent}')
        print(f'Money won:       {self.money_won}')
        print(f'Weeks simulated: {self.weeks_to_simulate}')





np.random.seed(1030) # ensure always the same results

sim = LotterySimulation(weeks_to_simulate=52000)
sim.run()
sim.print_summary()