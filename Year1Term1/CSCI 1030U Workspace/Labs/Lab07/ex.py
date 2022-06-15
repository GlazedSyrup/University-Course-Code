import json  # needed to load json files

def load_csv(path):
    # with open(...) as x loads a file for us as the variable x, this will be used each time you read/write a file
    # path is the string location of the file (which is passed into the function)
    # The "r" specifies that we want to READ the file only, not write
    with open(path, "r") as in_file:
        # We're going to open and read all of the contents of the file into a string
        csv_data = in_file.read()
       
        print(f"The loaded csv data from {path} contains:\n{csv_data}")

def write_json(path):
    with open(path, "w") as out_file:
        json_data = {
            "People": [
                {
                    "Name": "Tom",
                    "Age": 20,
                    "BDay": "1/1/2000"
                },
                {
                    "Name": "Jeff",
                    "Age": 40,
                    "BDay": "10/10/1980"
                },
                {
                    "Name": "Bob",
                    "Age": 10,
                    "BDay": "10/10/2010"
                }
            ]
        }
        # Write (dump) the json data to the file we opened earlier on line 49
        json.dump(json_data, out_file)
        print(f"Wrote json data to {path} successfully")

load_csv("apartment_building_evaluation.csv")
write_json("ex_write_json.json")
