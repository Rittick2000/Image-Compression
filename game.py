import PIL
from PIL import Image
import os
img=Image.open("IMG_20200929_192323.jpg")
mywidth,myheight=map(int,img.size)
img=img.resize((mywidth,myheight),PIL.Image.ANTIALIAS)
img.save("mysign_photo11.jpg")
