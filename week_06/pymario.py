def main():
    """

    :return: Main functions.
    """
    number = int(input("Number of boxes: "))
    printf(number)
    printg(number)
    print("Davi")


def printf(n=8, symbol="?"):
    """
    :param symbol: Symbol you want to print
    :param n: Number of boxes.
    :return: The boxes on the screen (void)
    """
    final = symbol * n
    print(final, end="davi")
    return


def printg(n=5):
    """

    :param n: Number of bricks
    :return: The bricks
    """
    for i in range(n):
        print((n-i-1) * " " + (i+1) * "#" + "  " + (i+1) * "#", end="\n")
    return


if __name__ == '__main__':
    main()
