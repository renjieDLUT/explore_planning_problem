import pandas as pd
import os
import numpy


def seperate_print(*data, title: str = None):
    print("-"*40)
    if title:
        title = title.center(40)
        print(title)
    print("-"*40)
    print(*data)
    print('\n')


def set_pd_display():
    pd.set_option('display.max_rows', 100)
    pd.set_option('display.max_columns', 500)
    pd.set_option('display.float_format', lambda x: '%.10f' % x)


# set_pd_display()

data = range(1, 3)
pd_data = pd.Series(data)
seperate_print(pd_data, pd_data.dtypes, title='Series Test1')

pd_data = pd.Series(data=['010', '022', '021', '023'], index=[
                    'beijing', 'tianjing', 'shanghai', 'chognqing'])

seperate_print(pd_data, title='Series Test2')

data = {'col_1': [1, 2], 'col_2': [2, 3]}
df = pd.DataFrame(data)
seperate_print(df, title='DataFrame Test1')

data = [['rj', 29],
        ['hxj', 28]]
df = pd.DataFrame(data, index=range(1, 3), columns=['name', 'age'])
seperate_print(df, title='DataFrame Test2')

data_list = [['110000', '北京', 4010.4, 707.21, 1057.87],
             ['120000', '天津', 2318.02, 1423.45, 4051.2],
             ['130000', '河北', 3873.16, 1073.04, 2676.77],
             ['140000', '山西', 26229.57, 5951.44, 10415.53],
             ['150000', '内蒙古', 9945.73, 3029.35, 5764.29]]
df = pd.DataFrame(data_list, columns=[
                  '省份代码', '省份名称', '资产总计', '固定资产净额', '固定资产原价'])

seperate_print(df, title='district'.title())
seperate_print(df['省份代码'], title='district code'.title())
seperate_print(df.loc[1], type(df.loc[1]), title='天津')
seperate_print(df.dtypes, title='data type'.title())


path = '/home/renjie/renjie_ws/dataset/av2/tmp/7737aaba-4306-4ca0-a2e2-c90a77a9523f'
files = [os.path.join(path, p)
         for p in os.listdir(path) if p.endswith('parquet')]

with open(files[0], 'rb+') as fd:
    df = pd.read_parquet(fd)

seperate_print(df, title='Scenario')
seperate_print(df.columns, title='column index'.upper())
seperate_print(df.loc[49], title='record id 49')
seperate_print(df.loc[df.shape[0]-1], title='last record')


group_df = df.groupby('track_id')

seperate_print(group_df.get_group('256856'), title='track_id 256856')
seperate_print(group_df.head(1), title='track_id head 1')
index = group_df.head(1).index

seperate_print(df['timestep'].get(index))

group_df = df.groupby(['object_category'])
seperate_print(group_df.indices.keys(),title='category type')
seperate_print(group_df.get_group(2),title="category 2")

group_df = df.groupby(['track_id'])
seperate_print(group_df.indices.keys())
# seperate_print(group_df.get_group())

index=df.groupby('track_id').head(1).index
seperate_print(index,type(index))
index=index.values.tolist()
seperate_print(index,type(index))
track_first_step_df=df['object_category'].get(index)
seperate_print(track_first_step_df)

seperate_print(df.loc[1028])