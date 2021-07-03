fibonaccis = dict()


def main():
    """

    :return: Fibonacci number
    """
    number = int(input("Posição do número: "))
    print(f"O {number}º número da sequência de Fibonacci é {fibonacci(number)}")


def fibonacci(n):
    if n == 1 or n == 2:
        return 1
    else:
        if n in fibonaccis.keys():
            return fibonaccis[n]
        else:
            fibonaccis[n] = fibonacci(n-1) + fibonacci(n-2)
            return fibonaccis[n]


if __name__ == '__main__':
    main()
