import json
import random

with open('./data.json', 'r') as file:
    data = json.load(file)

for i, item in enumerate(data):
    item["category"] = random.randint(1, 10)

with open('updated_data_with_enum_v2.json', 'w') as file:
    json.dump(data, file, indent=4)

