def main():
    """

    :return: void (cough)
    """
    cough(3)
    return


def cough(times):
    """
    :param times: How many times you want to cough
    :return: Some coughs
    """
    for i in range(times):
        print("Cough")


if __name__ == '__main__':
    main()
