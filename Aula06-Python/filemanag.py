import os
import subprocess


def main():
    count = 0
    for folder, subfolder, filename in os.walk('/home'):
        if 'messages.json' in filename:
            subprocess.Popen(os.path.join(folder, filename[0]))
            break

    print(count)
    return


if __name__ == '__main__':
    main()
