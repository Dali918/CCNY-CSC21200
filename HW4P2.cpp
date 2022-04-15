#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;
/*Write a program that counts the number of letters in each word of the Gettysburg
Address and stores these values into a histogram array. The histogram array should
contain 10 elements representing word lengths 1 – 10. After reading all words in the
Gettysburg Address, output the histogram to the display*/

int main()
{
    /*****************************************/
    string Name;
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/

    string line, substring;
    stringstream string_stream;
    vector<string> word_vector;

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

    std::size_t found;
    while (getline(read, line, '.')) // for each line, chop it up into words
    {

        while (line.find(" ") != std::string::npos)
        {

            found = line.find(" ");                                             // locate the position of a space
            substring = line.substr(0, found);                                  // get word
            if (!std::count(word_vector.begin(), word_vector.end(), substring)) // check if word is not in string vector
                word_vector.push_back(substring);                               // add word to word vector

            // cout << substring << endl;                            // print for debugging purposes
            line = line.substr(found + 1, line.length() - found); // update the phrase
        }

        word_vector.push_back(line); // add the last word
    }

    for (string &elem : word_vector)
    {
        // remove punctuation marks
        if (elem.find(".") != std::string::npos)
        {
            elem.erase(elem.find("."), 1);
        }

        if (elem.find(",") != std::string::npos)
        {
            elem.erase(elem.find(","), 1);
        }
    }

    // sort word vector by word length (descending) using selection sort
    int length = word_vector.at(0).length();
    for (int i = 0; i < word_vector.size(); i++)
    {
        int current_max = i; // set current 'max' index
        for (int j = i; j < word_vector.size(); j++)
        {

            if (word_vector.at(j).length() > word_vector.at(current_max).length())
            {
                current_max = j; // set new current max index;
            }
        }

        swap(word_vector.at(i), word_vector.at(current_max)); // swap new max with old max using swap function from algorithm
    }

    cout << "Printing the 10 longest words: " << endl;
    cout << "--------------------------------------" << endl;
    // Print Histogram
    for (int i = 0; i < 10; i++)
    {
        cout << "word " << i + 1 << ": " << word_vector.at(i) << " | length: " << word_vector.at(i).length() << " | ";
        for (char &j : word_vector.at(i))
        {
            cout << '*';
        }
        cout << endl;
    }

    read.close(); // close stream

    return 0;
}