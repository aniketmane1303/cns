#include <bits/stdc++.h>
using namespace std;
string alpah_lower(string str)
{
    for (char c : str)
    {
        if (isalpha(c))
        {
            c += tolower(c);
        }
    }
    return str;
}
string encrypt(string text, string key)
{
    string cipher;
    for (int i = 0; i < text.size(); i++)
    {
        int val = text[i] - 'a' + key[i % (key.size())] - 'a';
        cipher += ('a' + (val % 26));
    }
    return cipher;
}
string decrypt(string cipher, string key)
{
    string text;
    for (int i = 0; i < cipher.size(); i++)
    {
        int val = cipher[i] - 'a' - (key[i % (key.size())] - 'a');
        text += ('a' + (val + 26) % 26);
    }
    return text;
}
int main()
{
    int choice;
    cout << "1. Encrypt\n2. Decrypt\nEnter your choice: ";
    cin >> choice;
    cin.get();
    if (choice == 1)
    {
        string plain, key;
        cout << "\nEnter plain text: ";
        getline(cin, plain);
        plain = alpah_lower(plain);
        cout << "\nEnter key: ";
        getline(cin, key);
        string cipher = encrypt(plain, key);
        cout << "\nEncrypted text is : " << cipher << endl;
    }
    else if (choice == 2)
    {
        string cipher, key;
        cout << "\nEnter cipher text: ";
        getline(cin, cipher);
        cipher = alpah_lower(cipher);
        cout << "\nEnter key: ";
        getline(cin, key);
        string plain = decrypt(cipher, key);
        cout << "\nDecrypted text is : " << plain << endl;
    }
    return 0;
}
