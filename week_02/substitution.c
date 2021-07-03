#include <cs50.h>
#include <stdio.h>

char alphabet[104];
string encrypt(string plain, char ciphertext[]);
bool key_validation(string key);
void alphabet_maker(string key);
int len(string a);
int main(int argc, string argv[])
{
    if (argc != 2 || len(argv[1]) != 26) {
        printf("Error 00: No key argument :(\n");
        return 1;
    }
    else {
        string k = argv[1];
        if (key_validation(k)) {
            string p = get_string("plaintext: ");
            alphabet_maker(k);
            char cipher[len(p)];
            encrypt(p, cipher);
            printf("ciphertext: ");
            int l = len(p);
            for (int i = 0; i < l; i++) {
                printf("%c", cipher[i]);
        }
            printf("\n");
            return 0;
        }
        else {
            return 1;
        }
    }
}
int len(string a) {
    int n = 0;
    for(int i = 0; a[i] != 0; i++) {
        n++;
    }
    return n;
}
void alphabet_maker(string key) {
    for (int i = 0; i < 26; i++) {
        int ascii = key[i];
        alphabet[i] = (char) 65+i;
        alphabet[i+26] = (char) 97+i;
        alphabet[i+52] = (char) ascii;
        alphabet[i+78] = (char) ascii+32;
        }

    }
string encrypt(string plain, char ciphertext[]) {
    int l = len(plain);
    for (int i = 0; i < l; i++) {
        int index = (int) plain[i];
        if (index >= 65 && index <= 122) {
            if (index < 97) {
                ciphertext[i] = alphabet[index-65+52];
            }
            else {
                ciphertext[i] = alphabet[index-97+26+52];
            }}
        else {
            ciphertext[i] = plain[i];
        }}
        return ciphertext;
}
bool key_validation(string key) {
    bool valid = true;
    char keys[26];
    for (int i = 0; i < 26; i++) {
        int ascii = key[i];
        for (int j = 0; j < i; j++) {
            if (keys[j] == key[i]) {
                return false;
                break;
            }
        }
        if (key[i-1] == key[i] || ascii < 65 || ascii > 122) {
            valid = false;
            break;
        }
        else if (ascii >= 97) {
            key[i] = (char) ascii - 32;
        }
        keys[i] = key[i];
    }
    return valid;
}
