import sys

people = {'Davi': '99195-2079',
          'Cauê': '93314-0788',
          'João': '93203-3990',
          'Samuel': '39299-2239'}
if sys.argv[1] in people.keys():
    print(f"Found! {people[sys.argv[1]]}")
    exit(0)
print("Not found!")
exit(1)