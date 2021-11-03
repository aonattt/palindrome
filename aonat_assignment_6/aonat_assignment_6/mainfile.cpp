//Aykut Onat
//Programming Assignment 6
#include <iostream>
#include <cstring>
using namespace std;

//String Class

class String {
private:
    char sValue[101];
public:
    //Default Constructor
    String()
    {}
    //Initialization Constructor
    String(const char s[]) {
        strcpy_s(sValue, s);
    }

    //Access Functions
    int Length();

    //Operators Overloading
    bool operator==(const String& s) {
        if (_strcmpi(sValue, s.sValue) == 0)
            return true;
        return false;
    }

    bool operator!=(const String& s) {
        if (_strcmpi(sValue, s.sValue) == 0)
            return false;
        return true;
    }

    bool operator < (const String& s) {
        if (_strcmpi(sValue, s.sValue) < 0)
            return true;
        return false;
    }

    bool operator > (const String& s) {
        if (_strcmpi(sValue, s.sValue) > 0)
            return true;
        return false;
    }

    char& operator [] (const int indx) {
        if (indx<1 || indx>Length()) {
            exit(1);
        }
        return sValue[indx - 1];
    }

    //Mutator Functions
    void setElement(int indx, char ch);
    void ToUpper();
    void ToLower();

    //Input/Output Functions
    friend istream& operator>>(istream& bin, String& s);
    friend ostream& operator<<(ostream& out, const String& s);
};

//Outputs a string value
//of a String object
ostream& operator<<(ostream& out, const String& s) {

    out << s.sValue;

    return out;

}

//Reads a string value
istream& operator>>(istream& bin, String& s) {

    bin >> s.sValue;

    return bin;
}

//Length function returns the length 
//of the value of a String object
int String::Length()
{
    return strlen(sValue);
}

//setElement function assigns char value 
//to the position in the String object value specified 
//by indx value
void String::setElement(int indx, char ch) {
    if (indx <= Length()) {
        sValue[indx - 1] = ch;
    }
}

void String::ToUpper()
{

    for (int i = 0; i < Length(); i++)
        if ((sValue[i] >= 'a') && (sValue[i] <= 'z'))
            sValue[i] = sValue[i] - 32;
}

void String::ToLower()
{

    for (int i = 0; i < Length(); i++)
        if ((sValue[i] >= 'A') && (sValue[i] <= 'Z'))
            sValue[i] = sValue[i] + 32;
}

//function declarations
bool IsPalindrome(String str);
void GetStrings(String sList[], int& count);
void Sort(String sList[], int count);

int main() {
    String sList[100];  //list of string values
    String s;
    String palindrome = "\t*palindrome*";
    int count = 0;

    GetStrings(sList, count);
    //sort values in ascending order
    Sort(sList, count);
    cout << "\n" << endl;
    //Output table heading

    cout << "Sorted String List" << endl;
    cout << "\n" << endl;

    //Apply IsPalindrome function to each string value
    //Print out *palindrome* with the value on the same line
    //If the string value is a palindrome

    for (int i = 0; i < count;i++) {
        cout << "\n";
        cout << sList[i];
        if (IsPalindrome(sList[i])) {
            cout << palindrome;
        }
    }
    cout << "\n" << endl;
    //Output end of string list
    cout << "End of String List" << endl;
}

//function definitions
void GetStrings(String sList[], int& count) {
    String s;
    cout << "Please input a sequence of values,"
        "or the word quit to terminate: " << endl;

    while (s != "quit") {
        cin >> s;
        if (s != "quit") {         //except "quit"
            sList[count] = s;      //adds values into sList
            count++;               //counts the number of string added 
        }
    }
}



void Sort(String sList[], int count) {//sorts string values in ascending order
    String temp;
    int i, j;
    for (int i = (count - 1); i > 0; i--)
        for (int j = 0; j < i; j++)
            if (sList[j] > sList[j + 1]) {
                temp = sList[j];
                sList[j] = sList[j + 1];
                sList[j + 1] = temp;
            }
}

bool IsPalindrome(String s)
{
    s.ToLower(); //converts a String value to lower case version
    int leftPos = 1,                   //left character position in string s
        rightPos = s.Length();     //right character position in string s

    //compare left and corresponding right positions until not equal
    for (; leftPos < rightPos &&
        s[leftPos] == s[rightPos]; leftPos++, rightPos--)
        ;

    return leftPos >= rightPos;        //all compared character found equal
}