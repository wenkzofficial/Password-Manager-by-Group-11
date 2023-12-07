//group11ddpd3mi
//passwordmanager
//encryptanddecrypt
//wendika-monica-annisa
#include <iostream>
#include <string>
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

int main() {
    int choice;
    string text;
    cout << "Menu:\n1. Enkripsi Teks\n2. Dekripsi Teks\n";
    cout << "Pilih menu (1/2): ";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "Masukkan teks yang akan dienkripsi: ";
        getline(cin, text);
        string encryptedText = encryptText(text);
        cout << "Teks terenkripsi: " << encryptedText << endl;
    } else if (choice == 2) {
        cout << "Masukkan teks yang akan didekripsi: ";
        getline(cin, text);
        string decryptedText = decryptText(text);
        cout << "Teks terdekripsi: " << decryptedText << endl;
    } else {
        cout << "Pilihan menu tidak ada!" << endl;
    }

    return 0;
}