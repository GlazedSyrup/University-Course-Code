values = [1,2,3,4,5]

def list_to_string1(values):
    string = ""
    for i in range(len(values)):
        string = string + "" + str(values[i])
        if (i != len(values)-1):
            string = string + ","
        
    return string

print(list_to_string1(values))