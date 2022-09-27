
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <fstream>
#include <random>
#include <chrono>

using namespace std;
using namespace std::chrono;

string HexToBin(string hexdec)
{
    long int i = 0;
    stringstream ss;
    while (hexdec[i]) {

        switch (hexdec[i]) {
        case '0':
            ss << "0000";
            break;
        case '1':
            ss << "0001";
            break;
        case '2':
            ss << "0010";
            break;
        case '3':
            ss << "0011";
            break;
        case '4':
            ss << "0100";
            break;
        case '5':
            ss << "0101";
            break;
        case '6':
            ss << "0110";
            break;
        case '7':
            ss << "0111";
            break;
        case '8':
            ss << "1000";
            break;
        case '9':
            ss << "1001";
            break;
        case 'A':
        case 'a':
            ss << "1010";
            break;
        case 'B':
        case 'b':
            ss << "1011";
            break;
        case 'C':
        case 'c':
            ss << "1100";
            break;
        case 'D':
        case 'd':
            ss << "1101";
            break;
        case 'E':
        case 'e':
            ss << "1110";
            break;
        case 'F':
        case 'f':
            ss << "1111";
            break;
        default:
            ss << "\nInvalid hexadecimal digit "
                << hexdec[i];
        }
        i++;
    }
    return ss.str();
}

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

    //---collision---

    FileName = "25ksymbol10.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        out << random_string(10) << " " << random_string(10) << endl;
    }
    out.close();

    FileName = "25ksymbol100.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        out << random_string(100) << " " << random_string(100) << endl;
    }
    out.close();

    FileName = "25ksymbol500.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        out << random_string(500) << " " << random_string(500) << endl;
    }
    out.close();

    FileName = "25ksymbol1000.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        out << random_string(1000) << " " << random_string(1000) << endl;
    }
    out.close();

    //---difference---

    stringstream sss;
    string ran;
    FileName = "25ksymbol10_dif.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        ran = random_string(10);
        ran[0] = 'A';
        out << ran << " ";
        ran[0] = 'B';
        out << ran << endl;
    }
    out.close();

    FileName = "25ksymbol100_dif.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        ran = random_string(100);
        ran[0] = 'A';
        out << ran << " ";
        ran[0] = 'B';
        out << ran << endl;
    }
    out.close();

    FileName = "25ksymbol500_dif.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        ran = random_string(500);
        ran[0] = 'A';
        out << ran << " ";
        ran[0] = 'B';
        out << ran << endl;
    }
    out.close();

    FileName = "25ksymbol1000_dif.txt";
    out.open(FileName);
    for (int i = 0; i < 25000; i++)
    {
        ran = random_string(1000);
        ran[0] = 'A';
        out << ran << " ";
        ran[0] = 'B';
        out << ran << endl;
    }
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

void efec()
{
    auto startTime = high_resolution_clock::now();
    auto endTime = high_resolution_clock::now();
    duration<double> diff;
    stringstream ss;
    string s;
    ifstream in("konstitucija.txt");
    int i = 0;
    int j = 1;
    while (!in.eof())
    {
        i++;
        getline(in, s);
        ss << s << " ";
        if (i == j)
        {
            startTime = high_resolution_clock::now();
            hashas(ss.str());
            endTime = high_resolution_clock::now();
            diff = endTime - startTime;
            cout << diff.count() << endl;
            j *= 2;
            //cout << j << endl;
        }
    }
}

void collision()
{
    string FileName;
    string a, b;
    int FailCounter = 0;
    FileName = "25ksymbol10.txt";
    ifstream in(FileName);
    cout << "Testing the 10 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        if (hashas(a) == hashas(b))
        {
            FailCounter++;
        }
    }
    in.close();

    FileName = "25ksymbol100.txt";
    in.open(FileName);
    cout << "Testing the 100 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        if (hashas(a) == hashas(b))
        {
            FailCounter++;
        }
    }
    in.close();

    FileName = "25ksymbol500.txt";
    in.open(FileName);
    cout << "Testing the 500 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        if (hashas(a) == hashas(b))
        {
            FailCounter++;
        }
    }
    in.close();

    FileName = "25ksymbol1000.txt";
    in.open(FileName);
    cout << "Testing the 1000 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        if (hashas(a) == hashas(b))
        {
            FailCounter++;
        }
    }
    in.close();

    cout << "Collision results: " << FailCounter << endl;
}

float howSimilar(string a, string b)
{
    int matching = 0;
    float sim;
    for (int i = 0; i < 64; i++)
    {
        //cout << i << endl;
        if (a[i] == b[i])
        {
            matching++;
        }
    }
    //cout << matching << endl;
    sim = (float)matching/64*100;
    return sim;
}

float howSimilar1(string a, string b)
{
    int matching = 0;
    float sim;
    for (int i = 0; i < a.length(); i++)
    {
        //cout << i << endl;
        if (a[i] == b[i])
        {
            matching++;
        }
    }
    //cout << matching << endl;
    sim = (float)matching / a.length() * 100;
    return sim;
}

void similarity()
{
    float sim, sim1;
    float hex_simillarity = 0;
    float max_hex = 0;
    float min_hex = 100;

    float bits_simillarity = 0;
    float max_bits = 0;
    float min_bits = 100;

    string FileName;
    string a, b;
    FileName = "25ksymbol10_dif.txt";
    ifstream in(FileName);
    cout << "Testing the 10 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        sim = howSimilar(hashas(a), hashas(b));
        sim1 = howSimilar1(HexToBin(hashas(a)), HexToBin(hashas(b)));
        hex_simillarity += sim;
        bits_simillarity += sim1;
        if (sim > max_hex)
        {
            max_hex = sim;
        }
        else if (sim < min_hex)
        {
            min_hex = sim;
        }
        if (sim1 > max_bits)
        {
            max_bits = sim1;
        }
        else if (sim1 < min_bits)
        {
            min_bits = sim1;
        }
    }
    in.close();

    FileName = "25ksymbol100_dif.txt";
    in.open(FileName);
    cout << "Testing the 100 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        sim = howSimilar(hashas(a), hashas(b));
        sim1 = howSimilar1(HexToBin(hashas(a)), HexToBin(hashas(b)));
        hex_simillarity += sim;
        bits_simillarity += sim1;
        if (sim > max_hex)
        {
            max_hex = sim;
        }
        else if (sim < min_hex)
        {
            min_hex = sim;
        }
        if (sim1 > max_bits)
        {
            max_bits = sim1;
        }
        else if (sim1 < min_bits)
        {
            min_bits = sim1;
        }
    }
    in.close();

    FileName = "25ksymbol500_dif.txt";
    in.open(FileName);
    cout << "Testing the 500 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        sim = howSimilar(hashas(a), hashas(b));
        sim1 = howSimilar1(HexToBin(hashas(a)), HexToBin(hashas(b)));
        hex_simillarity += sim;
        bits_simillarity += sim1;
        if (sim > max_hex)
        {
            max_hex = sim;
        }
        else if (sim < min_hex)
        {
            min_hex = sim;
        }
        if (sim1 > max_bits)
        {
            max_bits = sim1;
        }
        else if (sim1 < min_bits)
        {
            min_bits = sim1;
        }
    }
    in.close();

    FileName = "25ksymbol1000_dif.txt";
    in.open(FileName);
    cout << "Testing the 1000 symbol strings..." << endl;
    for (int i = 0; i < 25000; i++)
    {
        in >> a >> b;
        sim = howSimilar(hashas(a), hashas(b));
        sim1 = howSimilar1(HexToBin(hashas(a)), HexToBin(hashas(b)));
        hex_simillarity += sim;
        bits_simillarity += sim1;
        if (sim > max_hex)
        {
            max_hex = sim;
        }
        else if (sim < min_hex)
        {
            min_hex = sim;
        }
        if (sim1 > max_bits)
        {
            max_bits = sim1;
        }
        else if (sim1 < min_bits)
        {
            min_bits = sim1;
        }
    }
    in.close();

    cout << "Similarity results: " << endl;
    cout << "Minimal HEX: " << min_hex << endl;
    cout << "Maximum HEX: " << max_hex << endl;
    cout << "Average HEX: " << hex_simillarity/100000 << endl;

    cout << "Minimal BITS: " << min_bits << endl;
    cout << "Maximum BITS: " << max_bits << endl;
    cout << "Average BITS: " << bits_simillarity / 100000 << endl;

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
        efec();
    }
    cout << "Ar norite padaryti kolizijos testa? [Y/N] ";
    while (true)
    {
        cin >> ats;
        if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
            cout << "Y/N ";
        else break;
    }
    if (ats == 'Y' || ats == 'y')
    {
        collision();
    }
    cout << "Ar norite padaryti panasumo testa? [Y/N] ";
    while (true)
    {
        cin >> ats;
        if (ats != 'y' && ats != 'n' && ats != 'Y' && ats != 'N')
            cout << "Y/N ";
        else break;
    }
    if (ats == 'Y' || ats == 'y')
    {
        similarity();
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