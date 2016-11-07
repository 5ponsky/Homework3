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
    cout << "BREAK" << endl << endl;

    s1 += s2;
    check(s1, "s1");
    s2 = s1;
    check(s2, "s2");
    s2 = " Sponsky";
    check(s2, "s2");
    //check(s2[0], "s2");

    s1 += ", a college student";
    s2 = s1;
    s2 = "Liam Dillingham, aasdf";
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
    s2.insert(5, "Gilchrist");
    check(s2, "s2");
    s2.insert(14, s1);
    check(s2, "s2");
    s2.replace(4, 3, s1);
    check(s2, "s2");
    s2.replace(4, 3, "woo");
    check(s2, "s2");

    s1 = "test";
    s2 = "test";
    if(s1 == s2)
        cout << "equal\n";
    s1 = "t";
    if(s1 != s2)
        cout << "not equal\n";
    Mystring s3 = s2 + s1;
    cout << s3;
}
