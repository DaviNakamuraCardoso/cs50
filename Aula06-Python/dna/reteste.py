import re

sample = 'GTCGCGAGATAGATAGATAGATGGGAGATAGATAGATAGATAGATAGATAGATAGATGTSCFAFFF'
sequence = "AGAT"
n = 1
found = False
old_mo = sequence
while not found:
    sequence_re = re.compile(r"(%s){%i,100}" % (sequence, n))
    mo = sequence_re.search(sample)
    if not mo:
        found = True
        print(n-1)
    else:
        n = len(mo.group(0)) / len(sequence) + 1
