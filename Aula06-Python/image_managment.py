from PIL import Image, ImageFilter
import os


def main():
    """
    Main function
    :return: Void
    """
    directory = input('Path: ')
    blur(directory)


def blur(path):
    """
    Takes a path
    :param path: The current directory
    :return: Void
    """
    for filename in os.listdir(path=path):
        if filename.endswith('.jpg'):
            file = os.path.join(path, filename)
            with Image.open(file) as image:
                after_0 = image.filter(ImageFilter.BLUR)
                after = after_0.filter(ImageFilter.GaussianBlur)
                after.save(filename.rstrip('.jpg') + '_blured.jpg')


if __name__ == '__main__':
    main()
