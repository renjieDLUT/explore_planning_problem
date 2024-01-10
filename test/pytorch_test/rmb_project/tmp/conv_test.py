import torch
from PIL import Image
from torchvision import transforms
from torch.nn import Conv2d
import matplotlib.pyplot as plt
from test.pytorch_test.rmb_project.tools import transform_invert

# path

img_path = "./data/raw_data/1/0B89KOA3.jpg"
img = Image.open(img_path)
transform = transforms.Compose((transforms.Resize((100, 100)), transforms.ToTensor()))

img_tensor: torch.Tensor = transform(img)
img_tensor.unsqueeze_(dim=0)

layer = Conv2d(3, 16, 4)
feature_map:torch.Tensor = layer(img_tensor)


for i in range(feature_map.size()[1]):
    feature_img = transform_invert.transform_invert(feature_map[0, i:i+1, ...], transform)
    plt.imshow(feature_img)
    plt.show()
