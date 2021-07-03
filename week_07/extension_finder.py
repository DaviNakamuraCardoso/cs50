import os


def main():
    extension = input('Extension: ')
    for folder, subfolder, filename in os.walk('/home'):
        for file in filename:
            if file.endswith(extension):
                print(folder + file)
    return


if __name__ == '__main__':
    main()
