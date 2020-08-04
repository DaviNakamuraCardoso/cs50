# TODO
import csv
import cs50
import sys


def main():
    if len(sys.argv) < 2:
        print("Missing command line arguments")
        exit(1)
    elif len(sys.argv) > 2:
        print("Too much command line arguments")
        exit(1)
    else:
        search(sys.argv[1])
        exit(0)


def search(house):
    """

    :param house: String with house
    :return:
    """