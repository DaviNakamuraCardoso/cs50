import time

fibonaccis = [1, 1]


def main():
    position = int(input("Posição do número desejado: "))
    start = time.time()
    print(fibonacci(position))
    end = time.time()
    duration = end - start
    print(duration)


def fibonacci(n):
    global fibonaccis
    if n == 1 or n == 2:
        return 1
    else:
        for i in range(n-2):
            tmp = fibonaccis[1]
            fibonaccis[1] = sum(fibonaccis)
            fibonaccis[0] = tmp
        return fibonaccis[1]


if __name__ == '__main__':
    main()
