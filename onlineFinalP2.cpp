#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;
// map<string, int>
map<string, int> Encrypt(vector<string> container)
{
    string word;
    map<string, int> map;
    int sum;
    for (int i = 0; i < container.size(); i++)      //loop through string vector
    {
        sum = 0;
        word = container.at(i);
        for (int i = 0; i < word.length(); i++)
        {
            sum += static_cast<int>(word.at(i));        //calculate sum
        }

        map[word] = sum;            //create pair
    }

    return map;     //return map
}

bool IsUpper(char c) { return (c < 91); }

int main()
{
    string Name;
    /*****************************************/
    cout << "Student Enter Name" << endl;
    cin >> Name;
    cout << "---------  -------------------------------------" << endl;
    cout << "FIle: " << __FILE__ << " Date: " << __DATE__ << endl;
    cout << "Student Name: " << Name << endl;
    cout << "----------------------------------------------" << endl;
    /*****************************************/

    const char *Words[] = {"double-007", "will", "arrive", "in", "Prague",
                           "on", "the", "9:45AM", "train", "from", "Paris",
                           "and", "will", "meet", "Count", "Ugo", "at", "Cafe",
                           "Franz", "Kafka", "at", "Intellect_Strasse", "707",
                           "where", "he", "will", "pass", "the", "briefcase",
                           "upon", "receiving", "the", "password", "Attila"};

    int len = sizeof(Words) / sizeof(Words[0]);
    cout << "Calculated len: " << len << endl;
    cout << "******PRINTING PALABRA*******" << endl;

    vector<string> Palabra;
    for (int i = 0; i < len; i++)
    {
        Palabra.push_back(Words[i]);        //create string vector
    }
    for (int i = 0; i < Palabra.size(); i++)
    {
        cout << "\"" << Palabra.at(i) << "\"" << endl;      //print words
    }
    cout << "*****PRINTING ENCRYPT******" << endl;
    map<string, int> PlainTxt = Encrypt(Palabra);
    for (map<string, int>::iterator iter = PlainTxt.begin(); iter != PlainTxt.end(); iter++)
    {
        cout << "\"" << iter->first << "\" - " << iter->second << endl;
    }
    cout << "*****PRINTING WORDS THAT START WITH UPPER CASE******" << endl;
    for (map<string, int>::iterator iter = PlainTxt.begin(); iter != PlainTxt.end(); iter++)
    {

        const char *word = iter->first.c_str();
        int upper_count = count_if(&word[0], &word[1], IsUpper);
        if (upper_count > 0)
        {
            cout << "\"" << iter->first << "\" - " << iter->second << endl;
        }
    }
    cout << "********PRINTING CYPHER********" << endl;
    vector<int> Cypher;
    for (map<string, int>::iterator iter = PlainTxt.begin(); iter != PlainTxt.end(); iter++)
    {
        Cypher.push_back(iter->second);
    }
    for (int i = 0; i < Cypher.size(); i++)
    {
        cout << Cypher.at(i) << endl;
    }

    return 0;
}