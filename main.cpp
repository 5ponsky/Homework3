#include <iostream>
#include "Mystring.h"

using namespace std;

void check (const string s, const string name)
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
    Mystring s2name("woo");
    Mystring test = "stuff";
    test.push_back('a');

}
