import re

yes_re = re.compile(r'y(es)?(.*)', re.IGNORECASE)

answer = input("Do you agree?\n")
if mo := yes_re.search(answer):
    print("Agreed")
    print(f"Your message: {mo.group[0]}")
else:
    print("Not agreed")
