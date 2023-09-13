import os
import shutil


def makedir(new_dir):
    if not os.path.exists(new_dir):
        os.makedirs(new_dir)


data_dir = './data/raw_data'
split_dir = './data/split_data'
train_dir = os.path.join(split_dir, 'train')
test_dir = os.path.join(split_dir, 'test')
valid_dir = os.path.join(split_dir, 'valid')

train_pecent = 0.8
test_pecent = 0.1
valid_pecent = 0.1

for root, dirs, files in os.walk(data_dir):
    for dir in dirs:
        imgs = os.listdir(os.path.join(root, dir))
        imgs = list(filter(lambda x: x.endswith('.jpg'), imgs))  # filter
        img_count = len(imgs)

        for i in range(img_count):
            if i < img_count * train_pecent:
                out_dir = os.path.join(train_dir, dir)
            elif i < img_count * (train_pecent + test_pecent):
                out_dir = os.path.join(test_dir, dir)
            else:
                out_dir = os.path.join(valid_dir, dir)

            makedir(out_dir)

            target_path = os.path.join(out_dir, imgs[i])
            source_path = os.path.join(data_dir, dir, imgs[i])
            shutil.copy(source_path, target_path)

        print('class:{},train:{},test:{},valid:{}'.format(dir, img_count * train_pecent, img_count * test_pecent,
                                                          img_count * valid_pecent))
