// Decoding.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <fstream>
#include <iostream>
#include <string>
const char Alphabet[] = { 'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','0','1','2','3','4','5','6','7','8','9' };
const int Alphabet_Size = sizeof(Alphabet) / sizeof(Alphabet[0]);
const char Alphab[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
const int alphab_Size = sizeof(Alphab) / sizeof(Alphab[0]);


using namespace std;
int main()
{
    double result[36];
    for (int i = 0; i < 36; i++)
    {
        result[i] = 0;
    }
    string resultString = "";
    int charSum = 0;
    char d;
    double icSum = 0;
    ifstream input_file("plaintext.txt");
    if (!input_file) {
        cout << "Failed to open input file." << endl;
        return 1;
    }
    cout << "Im counting characters..." << endl;
    while (input_file.peek() != EOF)
    {
        input_file >> d;
        for (int i = 0; i < 36; i++)
        {
            if (Alphabet[i] == d || Alphab[i] == d)
            {
                result[i] += 1;
                resultString += d;
                charSum += 1;
                break;
            }
            else
            {
                resultString += d;
            }
        }
    }
    cout << "\n" << charSum << endl;
    for (int i = 0; i < 36; i++)
    {
        cout << Alphabet[i] << ":" << result[i] / charSum * 100 << "%" << endl;
    }
    for (int i = 0; i < 36; i++)
    {
        icSum += result[i] * (result[i] - 1);
    }
    double IC = icSum / (charSum * (charSum - 1));
    cout << "IC: " << IC << endl;

    input_file.close();
    return 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
