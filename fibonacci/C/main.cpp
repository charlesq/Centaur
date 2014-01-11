/* requirements 
 * Write a snippet to generate the element with specified index in the 
 * fibonacci number sequence.
 * Implement two funcion, one to generate the next element in the sequence.
 * the other to produce the element with the speicified index in the sequence.
 */

#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
unsigned long long  getFibonacciNumber(unsigned int  index)
{
 /* recursive version 
  * if (index == 0)
  *     return 0;    
  * if (index == 1)
  *     return 1;
  * return getFibonacciNumber(index-1) + getFibonacciNumber(index -2);
 */
  static vector<unsigned long long> *p = new vector<unsigned long long>({0, 1}); 
  auto &v = *p;
  if(v.size() >= index + 1)
      return v[index];
  while(v.size() < index + 1)
  {
      unsigned long long e = v[v.size()-1] + v[v.size()-2];
      v.push_back(e);     
  }
  return v.back();
}

long long  getNextFibonacciNumber(void)
{
    static unsigned long long a = 0, b =1;;
    static unsigned int checker = 0; 
    if (checker == 0)
    {
        ++checker;
        return a; 
    }
    if (checker == 1)
    {
       ++checker;
       return b; 
    }
    unsigned  long long ret = a + b;
    a = b;
    b = ret;
    return ret;
}

int main()
{
    unsigned int index = 0;      
    while (index < 50)
    {
         cout<<setfill(' ')<< setw(10) <<  getFibonacciNumber(index++) << " ";
         if (index % 10 == 0)
             cout << endl;
    }
    index = 0;
    while(index ++< 50)
    {
        cout <<setfill(' ') << setw(10) << getNextFibonacciNumber() << " ";
        if(index % 10 == 0)
            cout << endl; 
    }
    return 0;
}
