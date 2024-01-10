import json

data = {
    "number": 1,
    "name": "rj",
    "address": "beijing",
    "other": None,
}

json_str = json.dumps(data)
print("json object:", json_str)
python_dict = json.loads(json_str)
print("python dict:", python_dict)

with open("./res/person_info.json", "w") as f:
    json.dump(data, f)

reload_data = dict()
with open("./res/person_info.json", "r+") as f:
    reload_data = json.load(f)

print("reload_data:", reload_data, type(reload_data))
