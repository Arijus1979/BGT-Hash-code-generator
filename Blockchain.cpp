
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <random>

using namespace std;

long hashing(string input)
{
	int hash = 1; 
	int multiply = 3; 
	for (int i = 0; i < input.length(); i++)
	{
        hash = hash + input[i];
        hash *= multiply;
	}
    //cout << hash << endl;
	return abs(hash);
}

// function to convert decimal to hexadecimal
string decToHexa(int n)
{
    // char array to store hexadecimal number
    char hexaDeciNum[100];

    // counter for hexadecimal number array
    int i = 0;
    while (n != 0) {
        // temporary variable to store remainder
        int temp = 0;

        // storing remainder in temp variable.
        temp = n % 16;

        // check if temp < 10
        if (temp < 10) {
            hexaDeciNum[i] = temp + 48;
            i++;
        }
        else {
            hexaDeciNum[i] = temp + 55;
            i++;
        }

        n = n / 16;
    }

    // printing hexadecimal number array in reverse order
    stringstream ss;
    for (int j = i - 1; j >= 0; j--)
        ss << hexaDeciNum[j];

    return ss.str();
}

string to256bit(long hash)
{
    stringstream ss;
    for (int i = 2; i < 30; i++)
    {
        ss << decToHexa(abs((i*hash)));
    }
    return (ss.str()).substr(0, 64);
    
}

string hashas(string input)
{
    return to256bit(hashing(input));
}

string fromFile(string FileName)
{
    ifstream in(FileName);
    stringstream ss;
    string s;
    while (!in.eof())
    {
        in >> s;
        ss << s << " ";
    }
    return ss.str();
    in.close();
}

string random_string(string::size_type length)
{
    static auto& chrs = "0123456789"
        "abcdefghijklmnopqrstuvwxyz"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    thread_local static mt19937 rg{ random_device{}() };
    thread_local static uniform_int_distribution<string::size_type> pick(0, sizeof(chrs) - 2);

    std::string s;

    s.reserve(length);

    while (length--)
        s += chrs[pick(rg)];

    return s;
}

void generateFiles()
{
    stringstream ss;
    string FileName;
    FileName = "1symbol1.txt";
    ofstream out(FileName);
    out << random_string(1);
    out.close();
    FileName = "1symbol2.txt";
    out.open(FileName);
    out << random_string(1);
    out.close();
    //---
    FileName = "1000symbol1.txt";
    out.open(FileName);
    out << random_string(1000);
    out.close();
    FileName = "1000symbol2.txt";
    out.open(FileName);
    ss << random_string(1000);
    ss.str()[500] = 'Z';
    out << ss.str();
    out.close();
    //---
    FileName = "1000symbol3.txt";
    out.open(FileName);
    ss.str()[500] = 'A';
    out << ss.str();
    out.close();
}

void testing1()
{
    cout << "TEST 1" << endl;
    string FileName, data;
    FileName = "1symbol1.txt";
    ifstream in(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();
    FileName = "1symbol2.txt";
    in.open(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();
    //---
    cout << "TEST 2" << endl;
    FileName = "1000symbol1.txt";
    in.open(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();
    FileName = "1000symbol2.txt";
    in.open(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();
    //---
    cout << "TEST 3" << endl;
    FileName = "1000symbol2.txt";
    in.open(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();
    FileName = "1000symbol3.txt";
    in.open(FileName);
    while (!in.eof())
    {
        in >> data;
    }
    cout << hashas(data) << endl;
    in.close();

}


void initiate() //main
{
    char ats;
    string pav;
    cout << "Ar norite padaryti efektyvumo testa? [Y/N] ";
    while (true)
    {
        cin >> ats;
        if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
            cout << "Y/N ";
        else break;
    }
    if (ats == 'Y' || ats == 'y')
    {
        
    }
    cout << "Ar norite duomenis nuskaityti is failo? [Y/N] ";
    while (true)
    {
        cin >> ats;
        if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
            cout << "Y/N ";
        else break;
    }
    if (ats == 'Y' || ats == 'y')
    {
        cout << "Ar turite sugeneruotus failus? [Y/N] ";
        while (true)
        {
            cin >> ats;
            if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
                cout << "Y/N ";
            else break;
        }
        if (ats == 'Y' || ats == 'y')
        {
            testing1();
        }
        else
        {
            cout << "Ar noresite sugeneruoti failus? [Y/N] ";
            while (true)
            {
                cin >> ats;
                if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
                    cout << "Y/N ";
                else break;
            }
            if (ats == 'Y' || ats == 'y')
            {
                generateFiles();
            }
            else
            {
                cout << "Iveskite failo pavadinima: ";
                cin >> pav;
                cout << hashas(fromFile(pav)) << endl;
            }
        }
        
    }
    else
    {
        cout << "Iveskite norima uzkoduoti teksta: ";
        cin >> pav;
        cout << hashas(pav);
    }
}

int main()
{
    initiate();

}