//2020BTECS00020
#include <bits/stdc++.h>
using namespace std;
char shift_char(char c, int shift, char op)
{
    if (isalpha(c) && op == 'e')
    {
        char base = islower(c) ? 'a' : 'A';
        return char((c - base + shift) % 26 + base);
    }
    else if (isalpha(c) && op == 'd')
    {
        char base = islower(c) ? 'a' : 'A';
        return char((c - base - shift + 26) % 26 + base);
    }
    return c;
}
string encrypt_text(string text, int key)
{
    string encrypted = "";
    for (char c : text)
    {
        encrypted += shift_char(c, key, 'e');
    }
    return encrypted;
}
string decrypt_text(string text, int key)
{
    string decrypted = "";
    for (char c : text)
    {
        decrypted += shift_char(c, key, 'd');
    }
    return decrypted;
}
int main(int argc, char const *argv[])
{
    int choice, key;
    string text;
    cout << "Enter choice: ";
    cout << endl
         << "1. Encrypt | 2. Decrypt" << endl;
    cin >> choice;
    cin.get();
    if (choice == 1)
    {
        cout << "enter text: ";
        getline(cin, text);
        cout << "Enter key: ";
        cin >> key;
        string result = encrypt_text(text, key);
        cout << "encrypted text: " << result << endl;
    }
    else if (choice == 2)
    {
        cout << "enter encrypted text: ";
        getline(cin, text);
        cout << "Enter key: ";
        cin >> key;
        string result = decrypt_text(text, key);
        cout << "decrypted text: " << result << endl;
    }
    else
    {
        cout << "not a valid choice!" << endl;
    }
    return 0;
}