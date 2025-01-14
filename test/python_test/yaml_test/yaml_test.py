'''
Author: renjie renjie_dlut2016@163.com
Date: 2024-02-06 19:56:09
LastEditors: renjie renjie_dlut2016@163.com
LastEditTime: 2024-02-06 20:09:02
FilePath: /explore_planning_problem/test/python_test/yaml_test/yaml_test.py
Description: 这是默认设置,请设置`customMade`, 打开koroFileHeader查看配置 进行设置: https://github.com/OBKoro1/koro1FileHeader/wiki/%E9%85%8D%E7%BD%AE
'''
import yaml

with open('extend.yaml', 'r', encoding='utf-8') as file_stream:
    raw = yaml.safe_load(file_stream)
    print(raw, type(raw))

d1 = {"name": "renjie"}
d2 = {"name": "hxj"}
d1.update(d2)
print(d1)
