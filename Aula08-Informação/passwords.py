import time


def main():
    for i in range(0, 9999):
        print("%.4i" % i)
        time.sleep(0.01)


if __name__ == '__main__':
    main()
