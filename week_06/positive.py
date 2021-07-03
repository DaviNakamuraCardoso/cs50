def main():
    i = get_positive_int()
    print(str(i) + ' is a positive integer')


def get_positive_int():
    while True:
        n = int(input("Positive Integer: "))
        if n >= 0:
            break
    return n


if __name__ == '__main__':
    main()
