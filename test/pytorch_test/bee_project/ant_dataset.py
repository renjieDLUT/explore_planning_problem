import os

import torch.utils.data.dataset as dataset
import PIL.Image as Image
import torchvision.transforms


class AntDataset(dataset.Dataset):
    def __init__(self, path: str, transform):
        super(AntDataset, self).__init__()
        self.label_dict = {"ants": 0, "bees": 1}
        self.data_info: list = self.get_data_info(path)
        self.transform = transform

    def __len__(self):
        return len(self.data_info)

    def __getitem__(self, item):
        img_path, label = self.data_info[item]
        img = Image.open(img_path).convert("RGB")
        img = self.transform(img)
        return img, label

    def get_data_info(self, path: str):
        data_info = []
        for root, dirs, files in os.walk(path):
            for dir in dirs:
                imgs_path = os.listdir(os.path.join(root, dir))
                imgs_path = list(filter(lambda path_name: path_name.endswith("jpg"), imgs_path))
                label = self.label_dict[dir]
                for img_path in imgs_path:
                    data_info.append(( os.path.join(root, dir,img_path), label))
        return data_info
