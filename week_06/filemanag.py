import os
import subprocess


def main():
    count = 0
    for folder, subfolder, filename in os.walk('/home'):
        for file in filename:
            if file.endswith('.jpg'):
                subprocess.Popen(['see', os.path.join(folder, file)])
             

    print(count)
    return


if __name__ == '__main__':
    main()
