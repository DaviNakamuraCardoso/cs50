import turtle
import time


def main():
    lados = int(input("Número de lados: "))
    figure(lados)
    time.sleep(2)
    turtle.bye()
    return 0


def figure(n):
    angle = (180 * (n-2)) / n
    t = turtle.Turtle()
    t.penup()
    t.goto(0, 100)
    t.pendown()
    side = 1200 / n
    for i in range(n):
        t.forward(side)
        t.right(180 - angle)
    return


if __name__ == '__main__':
    main()
