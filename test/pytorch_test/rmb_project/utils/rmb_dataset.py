from ast import List
import os
from torch.utils.data import Dataset
from torchvision.io.image import read_image
from PIL import Image


class RMBDataset(Dataset):
    def __init__(self, data_dir, transform) -> None:
        super().__init__()
        self.labels_dict = {'1': 0, '100': 1}
        self.data_info: list = self.get_data_info(data_dir)
        self.transform = transform

    def get_data_info(self, data_dir):
        data_info = list()
        print(os.getcwd())
        for root, dirs, files in os.walk(data_dir):
            for dir in dirs:
                imgs = os.listdir(os.path.join(root, dir))
                imgs = list(filter(lambda x: x.endswith('.jpg'), imgs))

                for i in range(len(imgs)):
                    img_name = imgs[i]
                    img_path = os.path.join(root, dir, img_name)
                    label = self.labels_dict[dir]
                    data_info.append((img_path, label))
        return data_info

    def __len__(self):
        return len(self.data_info)

    def __getitem__(self, index):
        path, label = self.data_info[index]
        # img=read_image(path)
        img = Image.open(path).convert('RGB')
        if self.transform is not None:
            img = self.transform(img)
        return img, label
