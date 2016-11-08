#include <iostream>
#include "Mystring.h"

using namespace std;

void check (const Mystring s, const char* name)
{
    cout << "checking " << name << endl;
    cout << name << " contains " << s << endl;
    cout << name << " capacity() is " << s.capacity() << endl;
    cout << name << " length() is " << s.length() << endl;
    cout << name << " size() is " << s.size() << endl;
    cout << name << " max_size() is " << s.max_size() << endl << endl;
}

int main()
{
    Mystring s1("Liam");
    Mystring s2 = " Dillingham";
    check(s1, "s1");
    check(s2, "s2");
    s1 += s2;
    check(s1, "s1");
    s2 = s1;
    check(s2, "s2");
    s1 = "Liam";
    check(s1, "s1");
    s1 += ", a college student";
    check(s1, "s1");
    s1.clear();
    check(s1, "s1");
    s1.push_back('.');
    check(s1, "s1");
    check(s2, "s2");
    s2.append(s1);
    check(s2, "s2");
    s2.append(" At the U of A.");
    check(s2, "s2");
    s2.insert(5, "Gilchrist ");
    check(s2, "s2");
    s2.insert(35, s1);
    check(s2, "s2");
    s2.replace(6, 8, s1);
    check(s2, "s2");
    s2.replace(27, 8, "University of Arkansas.");
    check(s2, "s2");

    s1 = "A String";
    s2 = "A String";
    check(s1, "s1");
    check(s2, "s2");
    if(s1 == s2)
        cout << "The two Strings are equal\n";
    s1 = "Not a String";
    if(s1 != s2)
        cout << "The two strings are not equal\n";
    Mystring s3 = s2 + ", and " + s1;
    cout << "We can print a Mystring object:  " << s3 << endl;
    cout << "We can find the index of an occurence of one string object in another: " << s3.find_first_of(s1)
            << ". And with literals: " << s3.find_first_of("Not") << endl;

    cout << "We can print an individual letter: " << s3[5];
}
