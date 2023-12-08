#include <bits/stdc++.h>
using namespace std;
string format(string &str)
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
string encrypt(string &plain, int key)
{
    vector<vector<char>> matrix(key);
    int rowNumber = 0;
    int flag = 1;
    for (int i = 0; i < plain.size(); i++)
    {
        matrix[rowNumber].push_back(plain[i]);
        rowNumber += flag;
        if (rowNumber == 0)
            flag = 1;
        if (rowNumber == key - 1)
            flag = -1;
    }
    string cipher;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < matrix[i].size(); j++)
            cipher += matrix[i][j];
    }
    return cipher;
}
string decrypt(string &cipher, int key)
{
    vector<vector<int>> matrixDecry(key);
    int rowNumber = 0;
    int flag = 1;
    int n = cipher.length();
    for (int i = 0; i < n; i++)
    {
        matrixDecry[rowNumber].push_back(i);
        rowNumber += flag;
        if (rowNumber == (key - 1))
            flag = -1;
        if (rowNumber == 0)
            flag = 1;
    }
    vector<int> mapping;
    for (int i = 0; i < key; i++)
    {
        for (int j = 0; j < matrixDecry[i].size(); j++)
            mapping.push_back(matrixDecry[i][j]);
    }
    map<int, char> m;
    for (int i = 0; i < n; i++)
        m[mapping[i]] = cipher[i];
    string plain;
    for (int i = 0; i < n; i++)
        plain += m[i];
    return plain;
}
int main()
{
    int choice;
    cout << "1. Encrypt\n2. Decrypt\nEnter your choice: ";
    cin >> choice;
    cin.get();
    if (choice == 1)
    {
        string plain;
        int key;
        cout << "\nEnter plain text: ";
        getline(cin, plain);
        plain = format(plain);
        cout << "\nEnter key: integer value(depth): ";
        cin >> key;
        string cipher = encrypt(plain, key);
        cout << "\nEncrypted text is : " << cipher << endl;
    }
    else if (choice == 2)
    {
        string cipher;
        int key;
        cout << "\nEnter cipher text: ";
        getline(cin, cipher);
        cipher = format(cipher);
        cout << "\nEnter key: integer value(depth): ";
        cin >> key;
        string plain = decrypt(cipher, key);
        cout << "\nDecrypted text is : " << plain << endl;
    }
    return 0;
}
