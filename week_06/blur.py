from PIL import Image, ImageFilter

before = Image.open("/home/davi/Downloads/melado.jpg")
after = before.filter(ImageFilter.BLUR)
after.save("blurmelado.bmp")