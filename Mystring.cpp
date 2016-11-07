#include "Mystring.h"

//Default Constructor
Mystring::Mystring() { /// READY
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}

//Initialized Constructor
Mystring::Mystring(const char *s) { /// READY
    len = strlen(s);
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);
}

//Copy Constructor
Mystring::Mystring(const Mystring &orig) {  /// READY
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

//Destructor
Mystring::~Mystring() { /// READY
    delete[] ptr_buffer;
    len = 0;
    buf_size = 0;
}

//Change buffer size to n
void Mystring::reserve(size_type n) { /// READY
    if(buf_size >= n)
        return;
    buf_size = n;
}

//Get size of array
Mystring::size_type Mystring::size() const { /// READY
    return len;
}

//Return # of characters minus '\0'
Mystring::size_type Mystring::length() const { /// READY
    return len;
}

//Return size of array
Mystring::size_type Mystring::capacity() const { /// READY
    return buf_size;
}

//Return maximum size of array
Mystring::size_type Mystring::max_size() const { /// READY
    return npos - 4;
}

//Return true if string is empty
bool Mystring::empty() const { /// READY
    if(*ptr_buffer == '\0' && len == 0)
        return true;
    return false;
}

//**************************
//Operator Overloading
//**************************

//Copy Assignment
Mystring& Mystring::operator=(const Mystring &obj) { /// READY
    ptr_buffer = obj.ptr_buffer;
    buf_size = obj.buf_size;
    len = obj.len;
    return *this;
}

//Copy Assignment
Mystring& Mystring::operator=(const char *str) { /// READY
    len = strlen(str);
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, str);
    return *this;
}


// Array notation
char Mystring::operator[](size_type pos) const { /// READY
    return *(ptr_buffer + pos);
}

char& Mystring::operator[](size_type pos) { /// READY
    return *(ptr_buffer + pos);
}

// Append
Mystring& Mystring::operator+=(const Mystring& obj) { /// READY
    strcat(ptr_buffer, obj.ptr_buffer);
    return *this;
}

Mystring& Mystring::operator+=(const char * str) { /// READY
    strcat(ptr_buffer, str);
    return *this;
}

//**************************
//Modifying the String
//**************************

//Clear the contents
void Mystring::clear() { /// READY
    delete[] ptr_buffer;
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}

//Expand string by 1 (proportionally) and add a single new character on the end.
void Mystring::push_back(char c) { /// Ready
    len++, buf_size++;
    char *tempPtr = new char[len];
    tempPtr[len] = c;
    tempPtr[buf_size] = '\0';
    ptr_buffer = tempPtr;
}

//(OBJECT) concatenate a string of size n >= 0 to the end
Mystring& Mystring::append(const Mystring &obj) {  /// READY
    strcat(ptr_buffer, obj.ptr_buffer);
    return *this;
}

//(POINTER) concatenate a string of size n >= 0 to the end
Mystring& Mystring::append(const char * str) {  /// READY
    strcat(ptr_buffer, str);
    return *this;
}

//(OBJECT) Insert character into the string
Mystring& Mystring::insert(size_type pos, const Mystring& str) {  /// READY
    //Mystring *newMystring = new char[first.length() + second.length() + 1];
    char *temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str.c_str());
    strcat(ptr_buffer, temp);
    return *this;
}

//(POINTER) Insert character into the string
Mystring& Mystring::insert(size_type pos, const char * str) { /// READY
    char *temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str);
    strcat(ptr_buffer, temp);
    return *this;
}

//(OBJECT) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str) {

    //Find a way to deallocate SPAN spaces within the original string, and replace with new string
    //I.e. similar to INSERT, but with a truncation included.
    char *temp = ptr_buffer + start;
    strcpy(ptr_buffer + start, str.c_str());
    strcat(ptr_buffer, temp);
    return *this;
}

//(POINTER) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const char * str) {
    char *temp = ptr_buffer + start;
    strcpy(ptr_buffer + start, str);
    strcat(ptr_buffer, temp);
    return *this;
}

//**************************
//Convert to C-String
//**************************

//Convert to Character array
const char* Mystring::c_str() const { /// Ready
    return ptr_buffer;
}

//(OBJECT) Find beginning of string
Mystring::size_type Mystring::find_first_of(const Mystring& str, size_type pos) const { // we can kill 0 if we want

}

//(POINTER) Find beginning of string
Mystring::size_type Mystring::find_first_of(const char* str, size_type pos) const {

}


//************************************
//************************************
//Overloading Global Operators
//************************************
//************************************

//**************************
//Equality Overloading (==)
//**************************

//(OBJECT <-> OBJECT) equality
bool operator==(const Mystring& left, const Mystring& right) { /// Ready
    return strcmp(left.c_str(), right.c_str());
}

//(POINTER <-> OBJECT) equality
bool operator==(const char *left, const Mystring& right) { /// Ready
    return strcmp(left, right.c_str());
}

//(POINTER <-> POINTER) equality
bool operator==(const Mystring& left, const char *right) { /// Ready
    return strcmp(left.c_str(), right);
}

//**************************
//Inequality Overloading (!=)
//**************************

//(OBJECT <-> OBJECT) inequality
bool operator!=(const Mystring& left, const Mystring& right) {  /// Ready
    return strcmp(left.c_str(), right.c_str());
}

//(POINTER <-> OBJECT) inequality
bool operator!=(const char *left, const Mystring& right) { /// Ready
    return strcmp(left, right.c_str());
}

//(POINTER <-> POINTER) inequality
bool operator!=(const Mystring& left, const char *right) { /// Ready
    return strcmp(left.c_str(), right);
}

//**************************
//Concatenation Overloading (+)
//**************************

//Add two strings together end to beginning
Mystring operator+(const Mystring& first, const Mystring& second) { /// Ready
    char *temp = new char[first.length() + second.length() + 1];
    strcpy(temp, first.c_str());
    strcat(temp, second.c_str());
    return temp;
}

//**************************
//Output Overloading (<<)
//**************************

//Print out a character string
ostream& operator<<(ostream& out, const Mystring& str) { /// Ready
    out << str.c_str();
    return out;
}





