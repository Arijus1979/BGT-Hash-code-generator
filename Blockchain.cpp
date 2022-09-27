
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

int hashing(string input)
{
	int hash = 15; 
	int multiply = 999; 
	for (int i = 0; i < input.length(); i++)
	{
		hash = hash ^ (input[i]);
		hash = hash * multiply;
	}
    //auto s = std::to_string(hash);
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

string to256bit(int hash)
{
    stringstream ss;
    for (int i = 2; i < 15; i++)
    {
        ss << decToHexa(abs((i*hash)));
    }
    return (ss.str()).substr(0, 64);
    
}


int main()
{
	//decToHexa(hashing("test"));
	/*cout << hashing("1234") << endl;
	cout << hashing("TEST") << endl;
	cout << hashing("tesT") << endl;*/

    cout << "test: " << to256bit(hashing("testsdfasdf asd fasd fasd fa sd")) << endl;
    cout << "Test: " << to256bit(hashing("Testasdf asdf asd fasd fasd fasdf ")) << endl;
    cout << "TEST: " << to256bit(hashing("TESTasdf adff asd asd fasdasd fasd fasd fasd fasd fasd fasd f")) << endl;
    cout << "tesT: " << to256bit(hashing("tesTasdffaa sdf asd fasd fas dfasd fasdfasd fasd fasd fasd f asdf asd fasd fasd fasd fff f f f f")) << endl;
    cout << "tesT: " << to256bit(hashing("tesTasdffaa sdf asd fasd fas dfasd fasdfasd fasd fasd fasd f asdf asd fasd fasd fasd fff f f f a")) << endl;
    cout << "tesT: " << to256bit(hashing("tes Tasd ffaa")) << endl;
    cout << "tesT: " << to256bit(hashing("tesTa sdf faa")) << endl;
    cout << "tesT: " << to256bit(hashing("tesTasd f faa")) << endl;


    

   


}