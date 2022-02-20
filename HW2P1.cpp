// Dalitso Banda CSC21200 | Homework 2 Problem 1
#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

/*Write a program having a String class that contains a function that can reverse the order of the characters in a string. 
A palindrome is a word or group of words that read the same forward and backward. 
For example “madam” or “wow”. Write a program that takes a string argument from the command line 
and returns TRUE if the string is a palindrome.*/

// string class
class String
{
public:
   String(string input_word) : word{input_word} {}                                                     // constructor
   String &operator=(const String &string_object);                                                     // assignment operator
   friend bool operator==(const String &left, const String &right) { return left.word == right.word; } // equality operator
   String reverse();                                                                                   // reverse string member function
private:
   string word;
};

// check palindrome function
bool isPalindrome(string input)
{
   String string_object(input);
   return string_object == string_object.reverse();
}
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
   string input, copy;
   cout << "Enter a word" << endl;
   cin >> input;
   copy = input;
   std::reverse(copy.begin(), copy.end()); // using std::reverse reverses the string in place

   //check if palindrome and print message accordingly
   if (isPalindrome(input))
   {
      cout << input << " is a palindrome!" << endl;
      cout << "reversed word: " << copy << endl;
      cout << endl;
   }
   else
   {
      cout << input << " is NOT a palindrome!" << copy << endl;
      cout << "reversed word: " << copy << endl;
      cout << endl;
   }
   return 0;
}

// String class overloaded assignment operator definition
String &String::operator=(const String &string_object)
{
   this->word = string_object.word;
   return (*this);
}

// String class reverse member function
String String::reverse()
{
   // empty string
   string reversed = "";
   // reverse string using for loop
   for (int i = word.length() - 1; i >= 0; i--)
   {
      reversed += word.at(i);
   }

   // return reverse string by value
   return String(reversed);
}
