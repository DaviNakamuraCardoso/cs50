# Checks a texts readability based on the Coleman-Liau formula
text = input("Text: ")
words = text.split()
points = "?.!"
stuff = ",:-';"
nl = 0
nw = len(words)
ns = 0
for word in words:
    for char in word:
        if char in points:
            ns += 1
        elif char not in stuff:
            nl += 1

L = nl * 100 / nw
S = ns * 100 / nw

grade_float = (0.0588 * L) - (0.296 * S) - 15.8
grade = round(grade_float)
if grade < 1:
    print('Before Grade 1')
elif grade > 16:
    print('Grade 16+')
else:
    print(f"Grade {grade}")
