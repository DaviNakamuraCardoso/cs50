import sys
import cs50
import csv


def main():
    """

    :return: Void
    """
    if (len(sys.argv)) < 2:
        print("Missing command line arguments")
        exit(1)
    elif (len(sys.argv)) > 2:
        print("Too much command line arguments")
        exit(1)
    else:
        load(sys.argv[1])


def load(filename):
    """
db.execute(f"INSERT INTO students (first, middle, last, birth, house) VALUES ({names[0]},"
                        f" NULL, {names[1]}, {row['birth'],}, {row['house']});")
    :param filename: CSV filename
    :return: Void
    """
    db = cs50.SQL("sqlite:///students.db")
    with open(filename, "r") as file:
        reader = csv.DictReader(file)
        for row in reader:
            names = row['name'].split()
            if len(names) == 2:
                middle = "NULL"
                last = names[1]
            else:
                middle = names[1]
                last = names[2]
            first = names[0]
            house = row["house"]
            birth = int(row["birth"])
            db.execute("INSERT INTO students (first, middle, last, house, birth) VALUES(?, ?, ?, ?, ?)",
                       first, middle, last, house, birth)

    return


if __name__ == '__main__':
    main()










