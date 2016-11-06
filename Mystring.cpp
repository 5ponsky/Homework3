#include "Mystring.h"

//Default Constructor
Mystring::Mystring() {
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}

//Other Constructor
Mystring::Mystring(const char *s) {
    len = strlen(s);
    buf_size = len + 1;
}

//Copy Constructor
Mystring::Mystring(const Mystring &orig) {
    len = orig.length();
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, orig.ptr_buffer);
}

//Destructor
Mystring::~Mystring() {
    delete[] ptr_buffer;
    len = 0;
    buf_size = 0;
}

//Change buffer size to n
void Mystring::reserve(size_type n) {
    if(buf_size >= n)
        return;
    buf_size = n;
}

//Get size of array
Mystring::size_type Mystring::size() const {
    return len;
}

//Return # of characters minus '\0'
Mystring::size_type Mystring::length() const {
    return len;
}

//Return size of array
Mystring::size_type Mystring::capacity() const {
    return buf_size;
}

//Return maximum size of array
Mystring::size_type Mystring::max_size() const {
    return npos - 4;
}

//Return true if string is empty
bool Mystring::empty() const {
    if(*ptr_buffer == '\0' && len == 0)
        return true;
    return false;
}

//**************************
//Operator Overloading
//**************************

//Copy Assignment
Mystring& Mystring::operator=(const Mystring &obj) {

}

//Copy Assignment
Mystring& Mystring::operator=(const char *obj_ptr) {

    return *this;
}

//**************************
//Modifying the String
//**************************

//Clear the contents
void Mystring::clear() {
    delete[] ptr_buffer;
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}

//Push back to add more characters
void Mystring::push_back(char c) {
    char *tempPtr = new char[len + 1];
    tempPtr[len + 1] = c;
    //tempPtr[buf_size + 1];
    ptr_buffer = tempPtr;
    len++;
    buf_size++;
}

//(OBJECT) Append to the end of the string
Mystring& Mystring::append(const Mystring &str) {
    //use strcat

    return *this;
}

//(POINTER) Append to the end of the string
Mystring& Mystring::append(const char * str) {

    return *this;
}

//(OBJECT) Insert character into the string
Mystring& Mystring::insert(size_type pos, const Mystring& str) {
    return *this;
}

//(POINTER) Insert character into the string
Mystring& Mystring::insert(size_type, const char * str) {

}

//(OBJECT) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const Mystring& str) {

}

//(POINTER) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const char * str) {

}

//**************************
//Convert to C-String
//**************************

//Convert to Character array
const char* Mystring::c_str() const {
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
bool operator==(const Mystring& left, const Mystring& right) {
    return strcmp(left.c_str(), right.c_str());
}

//(POINTER <-> OBJECT) equality
bool operator==(const char *, const Mystring&) {

}

//(POINTER <-> POINTER) equality
bool operator==(const Mystring&, const char *) {

}

//**************************
//Inequality Overloading (!=)
//**************************

//(OBJECT <-> OBJECT) inequality
bool operator!=(const Mystring&, const Mystring&) {

}

//(POINTER <-> OBJECT) inequality
bool operator!=(const char *, const Mystring&) {

}

//(POINTER <-> POINTER) inequality
bool operator!=(const Mystring&, const char *) {

}

//**************************
//Concatenation Overloading (+)
//**************************

//Add two strings together end to beginning
Mystring operator+(const Mystring& first, const Mystring& second) {
    char *temp = new char[first.length() + second.length()];
    strcat(temp, first.c_str());
    strcat(temp, second.c_str());
    return temp;
}

//**************************
//Output Overloading (<<)
//**************************

//Print out a character string
ostream& operator<<(ostream& out, const Mystring& str) {
    //out = str.c_str();
}





