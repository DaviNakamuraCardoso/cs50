import time
import csv


def main():
    file = open('../Aula05-Estruturas-de-Dados/speller/dictionaries/large')
    for word in file:
        print(word.rstrip('\n'))
    return


if __name__ == '__main__':
    main()
