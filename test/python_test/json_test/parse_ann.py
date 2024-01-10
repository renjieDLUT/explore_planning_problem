from imp import reload
import json


file_path='/home/renjie/Downloads/annotation.json'
with open(file_path,'rb') as fd:
    reload_data=json.load(fd)

for key,value in reload_data.items():
    for k,v in value.items():
        print(v,end=" ")
    print(len(value))
    break