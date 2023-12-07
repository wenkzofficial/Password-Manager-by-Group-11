//group11ddpd3mi
//passwordmanager
//encryptanddecrypt
//wendika-monica-annisa
#include <iostream>
using namespace std;
int main() {
    srand(time(0));

    int length;
    cout << "Masukkan panjang password yang ingin dibuat: ";
    cin >> length;

    string symbols = "!@#$%^&*()_-+=<>?";
    string alphabet = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";

    string password;
    for (int i = 0; i < length; i++) {
        int choice = rand() % 2;
        if (choice == 0) {
            int index = rand() % symbols.length();
            password += symbols[index];
        } else {
            int index = rand() % alphabet.length();
            password += alphabet[index];
        }
    }

    cout << "Password yang dibuat: " << password << endl;

    return 0;
}