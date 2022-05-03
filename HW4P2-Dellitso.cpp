#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;
/*Write a program that counts the number of letters in each word of the Gettysburg
Address and stores these values into a histogram array. The histogram array should
contain 10 elements representing word lengths 1 – 10. After reading all words in the
Gettysburg Address, output the histogram to the display*/

int main()
{
    // string Name;
    // /*****************************************/
    // cout << "Student Enter Name" << endl;
    // cin >> Name;
    // cout << "---------  -------------------------------------" << endl;
    // cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    // cout << "Student Name: " << Name << endl;
    // cout << "----------------------------------------------" << endl;
    /*****************************************/

    string line, word;
    stringstream string_stream;
    vector<string> word_vector(0), line_vector(0);
    const int count_len = 32;
    int count_arr[count_len]{0};
    int index = 0;

    string fileName = "HW4message.txt";
    ifstream read{fileName};
    if (!read)
    {
        // Print an error and exit
        std::cerr << "message could not be opened for reading!\n";
        return 1;
    }
    else
    {
        cout << "File is open" << endl;
    }

    while (getline(read, line, '.'))
    {
        line_vector.push_back(line);
    }
    for (string &line : line_vector)
    {
        while (string_stream << line)
        {
            string_stream >> word;
            for (string &elem : word_vector)
            {
                if (elem == word)
                    break;
            }
            word_vector.push_back(word);
        }
    }

    int count = 0;
    for (string &elem : word_vector)
    {
        cout << "word " << ++count << ": " << elem << endl;
    }

    return 0;
}