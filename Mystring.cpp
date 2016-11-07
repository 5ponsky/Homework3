#include "Mystring.h"

//Default Constructor
Mystring::Mystring() {
    ptr_buffer = new char[1];
    *ptr_buffer = '\0';
    len = 0;
    buf_size = 1;
}

//Initialized Constructor
Mystring::Mystring(const char *s) {
    len = strlen(s);
    buf_size = len + 1;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, s);
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
    char *temp = ptr_buffer;
    ptr_buffer = new char[buf_size];
    strcpy(ptr_buffer, temp);
    delete[] temp;
}

//Get size of array
Mystring::size_type Mystring::size() const { //////// DONE
    return len;
}

//Return # of characters minus '\0'
Mystring::size_type Mystring::length() const { //////// DONE
    return len;
}

//Return size of array
Mystring::size_type Mystring::capacity() const { //////// DONE
    return buf_size;
}

//Return maximum size of array
Mystring::size_type Mystring::max_size() const { //////// DONE
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
Mystring& Mystring::operator=(const Mystring &obj) { //////// DONE
    reserve(obj.len);
    strcpy(ptr_buffer, obj.ptr_buffer);
    len = obj.len;
    return *this;
}

//Copy Assignment
Mystring& Mystring::operator=(const char *str) { //////// DONE
    reserve(strlen(str));
    strcpy(ptr_buffer, str);
    len = strlen(str);
    return *this;
}


// Array notation
char Mystring::operator[](size_type pos) const { /// READY
    return *(ptr_buffer + pos);
}

char& Mystring::operator[](size_type pos) {
    return *(ptr_buffer + pos);
}

// Append
Mystring& Mystring::operator+=(const Mystring& obj) {
    len = len + obj.len;
    reserve(len);
    strcat(ptr_buffer, obj.ptr_buffer);
    return *this;
}

Mystring& Mystring::operator+=(const char * str) {
    len = len + strlen(str);
    reserve(len);
    strcat(ptr_buffer, str);
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

//Expand string by 1 (proportionally) and add a single new character on the end.
void Mystring::push_back(char c) {
    buf_size++;
    reserve(buf_size);
    ptr_buffer[len] = c;
    ptr_buffer[buf_size] = '\0';
    len++;
}

//(OBJECT) concatenate a string of size n >= 0 to the end
Mystring& Mystring::append(const Mystring &obj) {
    len = len + obj.len;
    reserve(len);
    strcat(ptr_buffer, obj.ptr_buffer);
    return *this;
}

//(POINTER) concatenate a string of size n >= 0 to the end
Mystring& Mystring::append(const char * str) {
    len = len + strlen(str);
    reserve(len);
    strcat(ptr_buffer, str);
    return *this;
}

//(OBJECT) Insert character into the string
Mystring& Mystring::insert(size_type pos, const Mystring& obj) {
    len = len + obj.len;
    reserve(len);
    Mystring temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, obj.c_str());
    append(temp);
    return *this;
}

//(POINTER) Insert character into the string
Mystring& Mystring::insert(size_type pos, const char * str) { /// READY
    len = len + strlen(str);
    reserve(len);
    Mystring temp = ptr_buffer + pos;
    strcpy(ptr_buffer + pos, str);
    append(temp);
    return *this;
}

//(OBJECT) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const Mystring& obj) {
    len = len + obj.len;
    reserve(len);
    Mystring temp(ptr_buffer + start + span);
    strcpy(ptr_buffer + start, obj.ptr_buffer);
    append(temp);
    return *this;
}

//(POINTER) Replace some characters in a string
Mystring& Mystring::replace(size_type start, size_type span, const char * str) {
    len = len + strlen(str);
    reserve(len);
    Mystring temp(ptr_buffer + start + span);
    strcpy(ptr_buffer + start, str);
    append(temp);
    return *this;
}

//**************************
//Convert to C-String
//**************************

//Convert to Character array
const char* Mystring::c_str() const {
    return ptr_buffer;
}

//(OBJECT) Find beginning of string
Mystring::size_type Mystring::find_first_of(const Mystring& str, size_type pos) const {
    for(size_t i = pos; i < len; i++) {
        for(size_t j = 0; j < str.len; j++) {
            if(*(ptr_buffer + i) == *(str.ptr_buffer + j))
                return i;
        }
    }
    return npos;
}

//(POINTER) Find beginning of string
Mystring::size_type Mystring::find_first_of(const char* str, size_type pos) const { /// READY
    for(size_t i = pos; i < len; i++) {
        for(size_t j = 0; j < strlen(str); j++) {
            if(*(ptr_buffer + i) == *(str + j))
                return i;
        }
    }
    return npos;
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
    return !strcmp(left.c_str(), right.c_str());
}

//(POINTER <-> OBJECT) equality
bool operator==(const char *left, const Mystring& right) {
    return !strcmp(left, right.c_str());
}

//(POINTER <-> POINTER) equality
bool operator==(const Mystring& left, const char *right) {
    return !strcmp(left.c_str(), right);
}

//**************************
//Inequality Overloading (!=)
//**************************

//(OBJECT <-> OBJECT) inequality
bool operator!=(const Mystring& left, const Mystring& right) {
    return strcmp(left.c_str(), right.c_str());
}

//(POINTER <-> OBJECT) inequality
bool operator!=(const char *left, const Mystring& right) {
    return strcmp(left, right.c_str());
}

//(POINTER <-> POINTER) inequality
bool operator!=(const Mystring& left, const char *right) {
    return strcmp(left.c_str(), right);
}

//**************************
//Concatenation Overloading (+)
//**************************

//Add two strings together end to beginning
Mystring operator+(const Mystring& first, const Mystring& second) {
    Mystring temp = first;
    temp.append(second);
    return temp;
}

//**************************
//Output Overloading (<<)
//**************************

//Print out a character string
ostream& operator<<(ostream& out, const Mystring& obj) {
    out << obj.c_str();
    return out;
}





