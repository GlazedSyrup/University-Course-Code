def main():
    player_name = "Krogg"
    player_attack = 38.5
    player_defense = 20.0
    player_hp = 200

    boss_name = "Boss"
    boss_attack = 25
    boss_defense = 12.5
    boss_hp = 200

    round_num = 0


    while (player_hp > 0):
        round_num += 1
        print("\nRound", round_num)
        #Only option is to attack, thus the entire event script will be outputed with no intervention.

        #Player Attacks
        if (player_attack > boss_defense):
            boss_hp = boss_hp - (player_attack - boss_defense)
            print(player_name, "does", (player_attack - boss_defense), "points of damage to", boss_name)

        else: #(player_attack <= boss_defense):
            print(boss_name, "took 0 damage")

        #Boss Attacks
        if (boss_attack > player_defense):
            player_hp = player_hp - (boss_attack - player_defense)
            print(boss_name, "does", (boss_attack - player_defense), "points of damage to", player_name)

        else: #(boss_attack <= player_defense):
            print(player_name, "took 0 damage")
            player_hp = player_hp - boss_attack

        print(boss_name + ":", boss_hp)
        print(player_name + ":", player_hp)
        


        if (boss_hp <= 0):
            print(player_name, "has won.  You are victorious!")
            break

        elif (player_hp <= 0):
            print(boss_name, "has won.  You have been defeated!")
            break
    return 0

main()
