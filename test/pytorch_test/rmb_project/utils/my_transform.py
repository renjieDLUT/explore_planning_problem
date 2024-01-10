import random

from PIL import Image
import numpy as np
import matplotlib.pyplot as plt


class AddPepperNoise:
    def __init__(self, snr: float, p: float):
        assert isinstance(snr, float) and isinstance(p, float)
        self.snr = snr
        self.p = p

    def __call__(self, img: Image.Image) -> Image.Image:
        if random.uniform(0, 1) < self.p:
            img_: np.ndarray = np.array(img).copy()
            h, w, c = img_.shape
            signal_percent = self.snr
            snr_percent = 1 - signal_percent
            mask = np.random.choice([0, 1, 2], [h, w, 1], p=[signal_percent, snr_percent / 2, snr_percent / 2])
            mask = np.repeat(mask, 3, axis=2)
            img_[mask == 1] = 0
            img_[mask == 2] = 255
            return Image.fromarray(img_).convert("RGB")
        else:
            return img


if __name__ == "__main__":
    data = np.full( [100, 100, 3],100)
    data=data.astype(dtype= np.ubyte)
    img = Image.fromarray(data).convert("RGB")
    img = AddPepperNoise(0.9, 0.9)(img)
    plt.imshow(img)
    plt.show()
