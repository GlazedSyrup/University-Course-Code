import json
from csv import reader

def load_matching_data(min_score, min_stories, min_units):
    path = 'apartment_building_evaluation.csv'
    data = []
    with open(path, 'r') as in_file:
        csv_data = reader(in_file)
        for row in csv_data:
            if (float(row[24]) >= float(min_score)) and (float(row[2]) >= float(min_stories)) and (float(row[3]) >= float(min_units)):
                data.append({'address': row[26],'score': float(row[24]),'num_stories': int(float(row[2])),'num_units': int(float(row[3]))})

    return data

results = load_matching_data(85, 28, 300)
print(results)
print(len(results))


def save_summary(results, filename):
    with open(filename, 'w') as out_file:
        json_data = []
        for i in range(len(results)):
            json_data.append(results[i])
        json.dump(json_data, out_file)

save_summary(results, 'apartment_summary.json')
with open('apartment_summary.json', 'r') as file:
    for line in file:
        print(line)
