using namespace std;
#include <iostream>
#include <vector>
#include <cctype>
#include <string>


string removeSymbols(const char input[]) {
   string clean;
     for (int i = 0; input[i] != '\0'; i++) {
       if (isalpha(input[i]) || isspace(input[i])) {
             clean += input[i];
           
        }
    }
   return clean;
}


int length(const char* msg) {
    const char* p = msg;
    int count = 0;
    while (*p != 0) {
        ++p;
        ++count;
    }
    return count;
}   

int indexof(const char* msg, char c) {
    if (msg == nullptr) {
        return -1; 
    }
    
    int index = 0;
    const char* p = msg;
    while (*p != '\0') {
        if (*p == c) {
            return index; 
        }
        p++;      
        index++;  
    }

    index = -2;
    return index;
}

string replace(const char* msg, char c, char replacement) {
    const char* p = msg;
    string word;

    while (*p != '\0') {
        if (*p == c) {
            word += replacement;
        } 
        else {
            word += *p;
        }
        p++;
    }
    return word;
}

char* concat(const char* msg, const char* msgTwo) {
    int len1 = length(msg);
    int len2 = length(msgTwo);
    const char* p = msg;
    const char* q = msgTwo;
    char* newWord = new char[len1 + len2 + 1];
    char* temp = newWord;
    

    while (*p != '\0') {
        *temp = *p; 
        temp++;     
        p++;
    }
    
    while (*q != '\0') {
        *temp = *q;
        temp++;
        q++;
    }
    *temp = '\0';
   
    return newWord;
}


int main() {
    string mystring = "";
    string mystringtwo = "";
   
    int index = 0;
    char letterToFind;
    char replacement;

    //Enter a word
    cout << "Enter a word or phrase for the test." << endl;
    cin >> mystring;
    const char* myString = mystring.c_str();

    
    //TEST LENGTH
    cout << "The length of " << mystring << ", is: " << length(myString) << endl;

    //TEST INDEXOF
    cout << "Enter a character to search:" << endl;
    cin >> letterToFind;
    index = indexof(myString, letterToFind);
    if (index == -1){
        cout << "Entry cant be blank." << endl;
    }
    if (index == -2) {
        cout << "Character not found" <<endl;
    }
    if (index >= 0) {
        cout << "The index of this character in " << mystring << " , is: " << index << endl;
    }
    
    //TEST REPLACE
    cout << "Enter a Character to change." << endl;
    cin >> letterToFind;
    cout << "Enter a Character replacement." << endl;
    cin >> replacement;
    cout << myString << " has been changed to " << replace(myString, letterToFind, replacement) << endl;


    //TEST CONCACAT
    cout << "Enter a second word or phrase for the test." << endl;
    cin >> mystringtwo;
    const char* myStringTwo = mystringtwo.c_str();
    char* combined = concat(myString, myStringTwo);
    cout << "The combined word is: " << combined << endl;
    delete[] combined;
    return 0;
    
}
