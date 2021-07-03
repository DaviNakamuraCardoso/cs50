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
    :return: Array with the characters
    """
    db = cs50.SQL("sqlite:///students.db")
    array = db.execute('SELECT * FROM students WHERE house = ? ORDER BY last', house)
    for row in array:
        if row['middle'] != None:
            name = row['first'] + ' ' + row['middle'] + ' ' + row['last']
        else:
            name = row['first'] + ' ' + row['last']
        birth = row['birth']
        print(f"{name}, born {birth}")


if __name__ == '__main__':
    main()

