from PIL import Image
import glob, os

size = 128, 128

pic_files=glob.glob("*.png")
print(pic_files)
for infile in pic_files:
    file, ext = os.path.splitext(infile)
    with Image.open(infile) as im:
        im.thumbnail(size)
        im.save(file + "1.png", "png")f