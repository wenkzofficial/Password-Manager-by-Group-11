//group11ddpd3mi
//passwordmanager
//encryptanddecrypt
//wendika-monica-annisa
#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
string encryptText(const string& text) {
    string encryptedText = "";
    for (char c : text) {
        if (isalpha(c)) {
            if (islower(c)) {
                encryptedText += 'a' + (c - 'a' + 1) % 26;
            } else {
                encryptedText += 'A' + (c - 'A' + 1) % 26;
            }
        } else {
            encryptedText += c;
        }
    }
    return encryptedText;
}

string decryptText(const string& encryptedText) {
    string decryptedText = "";
    for (char c : encryptedText) {
        if (isalpha(c)) {
            if (islower(c)) {
                decryptedText += 'a' + (c - 'a' + 25) % 26;
            } else {
                decryptedText += 'A' + (c - 'A' + 25) % 26;
            }
        } else {
            decryptedText += c;
        }
    }
    return decryptedText;
}

string generatePassword(int length) {
    srand(time(0));
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
    return password;
}

int main() {
    int choice;
    cout << "Password Manager by Group 11" << endl;
    do {
        cout << "\nMenu:\n";
        cout << "1. Enkripsi Teks\n";
        cout << "2. Dekripsi Teks\n";
        cout << "3. Generate Password\n";
        cout << "4. Exit\n";
        cout << "Pilih menu (1/2/3/4): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                string text;
                cout << "Masukkan teks yang akan dienkripsi: ";
                getline(cin, text);
                string encryptedText = encryptText(text);
                cout << "Teks terenkripsi: " << encryptedText << endl;
                break;
            }
            case 2: {
                string encryptedText;
                cout << "Masukkan teks yang akan didekripsi: ";
                getline(cin, encryptedText);
                string decryptedText = decryptText(encryptedText);
                cout << "Teks terdekripsi: " << decryptedText << endl;
                break;
            }
            case 3: {
                int length;
                cout << "Masukkan panjang password yang ingin dibuat: ";
                cin >> length;
                string password = generatePassword(length);
                cout << "Password yang dibuat: " << password << endl;
                break;
            }
            case 4:
                cout << "terimakasih telah menggunakan PasswordManager by Group 11" << endl;
                break;
            default:
                cout << "Pilihan menu tidak ada!" << endl;
        }
    } while (choice != 4);

    return 0;
}