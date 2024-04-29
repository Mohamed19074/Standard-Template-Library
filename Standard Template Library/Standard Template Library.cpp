//Name :Mohamed Mahmoud
// CIS 1202 101
//Date :4/22/2024
//Prgram Name: Standard Template Library
//Program Description: This is for a function to calculate character offsets, throwing exceptions in error conditions.

#include <iostream>
#include <stdexcept>


using namespace std;


class InvalidCharacterException : public exception {
public: const char* what() const noexcept override {
       
    return "Invalid character! Only letters (A-Z, a-z) are allowed.";
    }
};


class InvalidRangeException : public exception {
public:  const char* what() const noexcept override {
        
    return "Invalid offset range! Resulting character is not a letter.";
    }
};

// Function to calculate character 
char character(char start, int offset) {

   
    if (!isalpha(start)) {
        throw InvalidCharacterException();
    }

   
    char result = start + offset;

   
    if (!isalpha(result)) {
        throw InvalidRangeException();
    }

    return result;
}

int main() {

    try {
        
        cout << "character('a', 1)  = "  << character('a', 1)   << endl; // should return 'b'
        cout << "character('a', -1) = " << character('a', -1)   << endl; // should throw an InvalidRangeException
        cout << "character('Z', -1) = " << character('Z', -1)   << endl; // should return 'Y'
        cout << "character('?', 5)  = "  << character('?', 5)   << endl; // should throw an InvalidCharacterException
    }
    catch (const exception& ex) {
        cerr << "Exception: " << ex.what() << endl;
    }

    return 0;
}
