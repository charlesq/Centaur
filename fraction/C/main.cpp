#include <vector>
#include <sstream>
#include <algorithm>
#include <iostream>
using namespace std;
string fractionConversion(int numerator, int denominator)
{
    stringstream ss;
    vector<int> remainders;
    vector<int> quotients;

    if (denominator == 0)
    {
          ss << "INFINITE";
          return ss.str(); 
    }
    if (numerator == 0)
        return "0";
    if (numerator < 0 || denominator < 0)
    {
        if (!(numerator < 0 &&  denominator <0))
            ss << "-";
        numerator = numerator < 0? -numerator: numerator; 
        denominator = denominator < 0? -denominator: denominator;
    }
    if ( numerator > denominator) 
    {
        ss << numerator / denominator;
        numerator = numerator % denominator;
        if (numerator == 0)
        {
            return ss.str();
        }
        ss << ".";
    } 
    else
       ss << "0.";
    int repeat_point = -1;
    while(numerator != 0)
    {
       vector<int>::iterator it = find (remainders.begin(), remainders.end(), numerator);
       if (it != remainders.end())
       {
           repeat_point = it - remainders.begin();
           break;
       }
       remainders.push_back(numerator);
       numerator *= 10;
       while(numerator < denominator)
       {
           quotients.push_back(0);
           remainders.push_back(0);
           numerator *= 10;
       }
       int ret = numerator / denominator;
       numerator = numerator % denominator;
       quotients.push_back(ret);
    }
    vector<int>::iterator it = quotients.begin();
    while(it != quotients.end())
    {
       if (repeat_point != -1 && it  - quotients.begin() == repeat_point)
           ss << "(";
       ss << *it++;
    }
    if (repeat_point != -1)
        ss << ")";
    return ss.str();
 }
int main()
{
    int numerator, denominator;
    while (true)
    {
        cout << "inputr numerator:" ;
        cin >> numerator;
        cout << "input denomiator:";
        cin >> denominator;
        cout << numerator << "/" << denominator << " = ";
        string h = fractionConversion(numerator, denominator);
        cout << h  << endl;
        char ch;
        cout << "Exit(Y/N)?";
        cin >> ch;
        if (ch == 'Y' || ch == 'y')
            break;
    }
    cout << endl;
    return 0;
}
