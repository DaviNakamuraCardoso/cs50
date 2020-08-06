import csv
import time


def main():
    dictionary = open('../Aula05-Estruturas-de-Dados/speller/dictionaries/large')
    file = open('../Aula07-SQL/Grupos de Trabalho 3AB - Sheet1.csv')
    reader = csv.DictReader(file)
    for row in reader:
        if row['E-mail p4ed'] == None:
            continue
        for word in dictionary:
            pswd = word.rstrip('\n')
            print(f"Checking {row['E-mail p4ed']} password {pswd}")
        for i in range(0, 9999):
            print(f"Checking {row['E-mail p4ed']} password %.4i" % i)
    return


if __name__ == '__main__':
    start = time.time()
    main()
    end = time.time()
    print(end-start)
    