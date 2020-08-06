import cs50
import csv


def main():
    load(filename='/home/davi/Documents/Code/Harvard-CS50/Aula07-SQL/Grupos de Trabalho 3AB - Sheet1.csv')


def load(filename):
    with open(filename) as file:
        reader = csv.DictReader(file)
        for row in reader:
            print(row['E-mail p4ed'])

    return


if __name__ == '__main__':
    main()
