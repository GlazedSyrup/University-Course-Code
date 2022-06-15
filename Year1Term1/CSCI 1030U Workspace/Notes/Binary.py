binary = 10101001
bin_dic = [128, 64, 32, 16, 8, 4, 2, 1]
decimal = 0

for i in range(8):
    decimal += int(str(binary)[i])* bin_dic[i]

print(decimal)



# 1*128 + 0*64 + 1*32
#1, 2, 4, 8, 16, 32, 64, 128