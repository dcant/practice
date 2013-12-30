#include <iostream>
#include <string>

using namespace std;

void revs(string & a, int s, int e);
void rot(string &a, int length, int num);

int main()
{
    cout << "Hello world!" << endl;
    string input = "abcdefg";
    cout << "Before rotate: " << input << endl;
    rot(input, input.length(), 3);
    cout << "After rotate: " << input << endl;
    return 0;
}

void revs(string &a, int s, int e)
{
    int length = e - s + 1;
    int mid = length / 2;
    for(int i = 0; i < mid; i++)
    {
        swap(a[s+i],a[e-i]);
    }
}

void rot(string &a, int length, int num)
{
    revs(a, 0, num-1);
    revs(a, num, length-1);
    revs(a, 0, length-1);
}
