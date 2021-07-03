def start(number, company):
    """

    :param number: The credit card number
    :param company: The company
    :return: True or False (Boolean)
    """
    if (number.startswith('51') or number.startswith('52') or number.startswith('53') or number.startswith('54')
    or number.startswith('55')) and company == 'MASTERCARD':
        return True
    elif (number.startswith('34') or number.startswith('37')) and company == 'AMEX':
        return True
    elif number.startswith('4') and company == 'VISA':
        return True
    else:
        return False


def checksum(number):
    """
    Checks the credit card sum according to Luhn's Algorithm
    :param number: Credit card number
    :return: Boolean
    """
    sum = 0

    for i in range(len(number)-2, -1, -2):
        value = 2 * int(number[i])
        strlen = len(str(value))
        if strlen == 1:
            sum += value
        elif strlen == 2:
            sum += value % 10
            value -= value % 10
            sum += value / 10
    for j in range(len(number)-1, -1, -2):
        sum += int(number[j])
    if (sum % 10) == 0:
        return True
    else:
        return False


def checknumber(number):
    """

    :param number: The credit card number
    :return: Void
    """
    if checksum(number):
        strlen = len(number)
        if strlen == 15 and start(number, 'AMEX'):
            print('AMEX')
        elif (strlen == 16 or strlen == 13) and (start(number, 'VISA')):
            print('VISA')
        elif strlen == 16 and start(number, 'MASTERCARD'):
            print('MASTERCARD')
        else:
            print('INVALID')
    else:
        print('INVALID')


while True:
    try:
        number = input('Number: ')
        checknumber(number)
        break
    except:
        continue
