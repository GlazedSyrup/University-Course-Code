
#Part 1
def intersect(list1, list2):
    list = []
    for i in (list1):
        for ii in (list2):
            if i == ii:
                list.append(i)

    return list


list1 = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19, 21, 23, 25]
list2 = [1, 4, 9, 15, 16, 25]

print(intersect(list1, list2))


#Part 2

def gregory_liebniz(number_of_terms):
    estimate = 0.0
    for n in range(number_of_terms):
        estimate += (4*(-1)**n)/(2*n+1)
        
    return estimate
    

print(f'estimate = {gregory_liebniz(10000000)}, actual value = 3.14159265358979323846')




#Part 3
#Code provided below
class Character:
    def __init__(self, name, hp, xp_gained, attack, defense, magic=0):
        self.name = name
        self.hp = hp
        self.max_hp = hp
        self.attack_power = attack
        self.defense_power = defense
        self.magic = magic
        self.xp_gained = xp_gained
        self.xp = 0
        self.level = 1

    def is_dead(self):
        if self.hp <= 0:
            return True
        return False

    def attack(self, other_character):
        if self.is_dead():
            print(self.name, 'cannot attack because he/she is dead.')
        else:
            damage = self.attack_power - other_character.defense_power
            if damage < 0:
                damage = 0
            other_character.hp -= damage
            print(self.name, 'does', damage, 'damage to', other_character.name)
            if other_character.hp <= 0:
                other_character.hp = 0
                print(f'{other_character.name} has died.')
                self.gain_xp(other_character)



    def heal(self, party):
        if self.is_dead():
            print(self.name, 'cannot heal because he/she is dead.')
        else:
            for party_member in party:
                if not party_member.is_dead():
                    party_member.hp += self.magic
                    if party_member.hp > party_member.max_hp:
                        party_member.hp = party_member.max_hp
                    print(f'{self.name} heals {self.magic} hp for {party_member.name}')

#Displays currents status of the character
    def __str__(self):
        f'{self.name} has {self.hp} HP.' 
        print(f'Character: {self.name} Level: {self.level}') #Outputs the characters stats
        print(f'XP: {self.xp}/{(self.level)*100}')
        print(f'HP: {self.hp}/{self.max_hp}')
        print(f'ATK: {self.attack_power}')
        print(f'DEF: {self.defense_power}')
        print(f'MAG: {self.magic}')

#This function adds xp to the character when they defeat another character, possibly leveling them up.
    def gain_xp(self, other_character):
        levels = [2, 3, 4, 5, 6, 7, 8, 9, 10]
        levels_min_xp = [100, 200, 300, 400, 500, 600, 700, 800, 900]
        level_attack_gain = [5.0, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5]
        level_defense_gain = [2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5, 2.5]
        level_magic_gain = [2.0, 1.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0, 2.0]
        for i in range(len(levels)):
            if levels[i] == self.level+1: #which index is the next level
                index = i
                break
        self.xp += other_character.xp_gained
        while True:
            if self.xp >= levels_min_xp[index]: #Character levels up
                self.xp -= levels_min_xp[index]
                self.level += 1
                self.attack_power += level_attack_gain[index]
                self.defense_power += level_defense_gain[index]
                if self.magic != 0:
                    self.magic += level_magic_gain[index]
                print(f'{self.name} leveled up! They are now level {self.level}') #Outputs the characters stats
                print(f'XP: {self.xp}/{levels_min_xp[index+1]}')
                print(f'HP: {self.max_hp} ---> {self.max_hp}')
                print(f'ATK: {self.attack_power - level_attack_gain[index]} ---> {self.attack_power}')
                print(f'DEF: {self.defense_power - level_defense_gain[index]} ---> {self.defense_power}')
                if self.magic != 0:
                    print(f'MAG: {self.magic - level_magic_gain[index]} ---> {self.magic}')
            
            if self.xp >= levels_min_xp[index+1]: #can the character still level up?
                index +=1
            else:
                break

#code provided below
# the constructor arguments are:
# name, hp, xpGained, attack, defense, magic
krogg = Character('Krogg', 180, 0, 20, 20)
glinda = Character('Glinda', 120, 0, 5, 20, 5)
geoffrey = Character('Geoffrey', 150, 0, 15, 15)
party = [krogg, glinda, geoffrey]
enemy1 = Character('Spider 1', 50, 100, 10, 1)
enemy2 = Character('Spider 2', 50, 100, 10, 1)
enemy3 = Character('Wolf 1', 100, 250, 15, 5)
enemy4 = Character('Wolf 2', 100, 250, 15, 5)
enemy5 = Character('Bear 1', 200, 350, 25, 10)
enemy6 = Character('Bear 2', 200, 350, 25, 10)
enemy7 = Character('Red Dragon', 300, 800, 30, 20)
enemy8 = Character('Blue Dragon', 400, 1000, 35, 20)
enemies = [enemy1, enemy2, enemy3, enemy4, enemy5, enemy6, enemy7, enemy8]



#initializing variable outside loop to determine which enemy is fighting currently
enemy_index = 0
while(True):

    enemy = enemies[enemy_index]

#player turn
    for party_member in party:
        while True:
#control what choices the current character can choose
            if party_member.magic != 0:
                print(f'\nWhat will {party_member.name} do?\nOptions Status or Attack or Heal')
                choice = input('Input: ')
            else:
                print(f'\nWhat will {party_member.name} do?\nOption: Status or Attack')
                choice = input('Input: ')

            choice = choice.lower()
            if choice == 'status':
                print('\n')
                party_member.__str__()

            elif choice == "attack" or (choice == "heal" and party_member.magic > 0):
                break
            else:
                print(f'Invalid Input: {choice}\n')
        

#perform the choice by calling functions
        if choice == 'attack':
            party_member.attack(enemy)
            if enemy.hp <= 0:
                break
            
        elif choice == 'heal':
            party_member.heal(party)
        



# enemy turn
#enemy attacks character with the lowest defense
    lowest_defense = party[0].defense_power
    if enemy.hp > 0:
        for character in party:
            if character.hp > 0:
                if character.defense_power <= lowest_defense:
                    lowest_defense = character.defense_power
                    target = character
        print('\n')
        enemy.attack(target)


    #check if any side has won
#check only for the enemy8's hp, as they will only be fought after all enemies are dead
    if enemies[7].hp <= 0:
        print("Congratulations, you've won the game!")
        break

#check if any characters are alive, if not then the player lost
    characters_left = 3
    for character in party:
        if character.hp <= 0:
            characters_left -= 1
    if characters_left == 0:
        print("Unfortunate, you've lost the game.")
        break



    #increase enemy index #next enemy
    if enemy.hp <= 0:
        enemy_index += 1
    #enemy enters the field 
        print(f'\n\n{enemies[enemy_index].name} has entered the fight!\n\n')



