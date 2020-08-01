import csv
import sys
import re
import os


def main():
    """
    Main Function
    :return: Void
    """
    if len(sys.argv) < 3:
        print("Missing command line arguments")
        exit(1)
    elif len(sys.argv) > 3:
        print("Too much command line arguments")
        exit(1)
    else:
        M = matrix(sys.argv[1])
        runs = sequences(sys.argv[2], M[0][1:])
        name = compare(M, runs)
        print(name)
        exit(0)


def matrix(filename):
    """

    :param filename: The csv file
    :return: A matrix with csv contents
    """
    file = open(filename)
    reader = csv.reader(file)
    csv_matrix = list(reader)
    return csv_matrix


def sequences(filename, A):
    """

    :param A: array with the DNA sequences
    :param filename: Text file with a DNA sequence
    :return: Array with the highest number of one sequence
    """
    longest_runs = []
    file = open(filename, "r")
    DNA = file.read()
    for sequence in A:
        n = 1
        found = False
        while not found:
            sequence_re = re.compile(r"(%s){%i,100}" % (sequence, n))
            mo = sequence_re.search(DNA)
            if not mo:
                found = True
            else:
                n = len(mo.group(0)) / len(sequence) + 1
        longest_runs.append(str(round(n-1)))
    return longest_runs


def compare(M, A):
    """

    :param M: Matrix with Names and DNA sequences
    :param A: Array with DNA values
    :return: String representing a person's name
    """

    for line in M[1:]:
        match = True
        for j in range(1, len(line)):
            if A[j-1] == line[j]:
                continue
            else:
                match = False
        if match:
            return line[0]
        else:
            continue
    return 'No match'


#main()
for filename in os.listdir('./sequences'):
    M = matrix('./databases/large.csv')
    runs = sequences('./sequences/'+ filename, M[0][1:])
    name = compare(M, runs)
    print('Run your program as python dna.py databasis/large.csv sequences/' + filename +
          '. Your program should output ' + name)

