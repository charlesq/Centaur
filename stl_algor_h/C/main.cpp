#include <algorithm>
#include <iostream>
#include <stdlib.h>
#include <string.h>
namespace exercise
{

class bidirectionalIteratorTag
{
};

template <typename T> void swap(T &a, T &b)
{
    if (a == b)
        return;
    T t = a; 
    a = b;
    b = t;
}

template <typename bidirectionalIterator>
void reverse(bidirectionalIterator _first, bidirectionalIterator _last, bidirectionalIteratorTag)
{
    if (_first + 1 >= _last)
        return;
    while(_first != --_last && _first < _last)
       swap(*_first++, *_last); 
}
template <typename bidirectionalIterator>
void rotate(bidirectionalIterator _first, bidirectionalIterator _middle, bidirectionalIterator _end, bidirectionalIteratorTag)
{
    if (_middle == _first || _middle == _end)
        return;
    reverse(_first, _end, bidirectionalIteratorTag());
    reverse(_first, _end - _middle + _first, bidirectionalIteratorTag() );
    reverse(_end -_middle + _first , _end, bidirectionalIteratorTag());
}
template <typename forwardIterator>
void rotate(forwardIterator _first, forwardIterator _middle, forwardIterator _last)
{
    if (_middle == _first || _middle  == _last)
        return;
    forwardIterator i = _first, j = _middle; 
    while(j != _last)
    { 
        swap(*i++, *j++);
        if (i == _middle)
           _middle  = j; 
        else if (j == _last)
            j = _middle;
    }
}
template<typename bidirectionalIterator>
bool next_permute(bidirectionalIterator _first, bidirectionalIterator _end, bidirectionalIteratorTag)
{
    bidirectionalIterator __first = _first;
    if (_first + 1 >= _end)
        return false;
    bidirectionalIterator i = _end - 1, j = _end -1;
    while(i != _first)
    {
        j = i --;
        if (*i >= *j)
            continue;
        j = _end; 
        while(*i > *--j) {} 
        swap(*i, *j);
        reverse(++i, _end, bidirectionalIteratorTag());
        return true;
    }
    reverse(__first, _end, bidirectionalIteratorTag());
    return false;
}
}

int main()
{
    int i = 0;
#if 0 
    while(i < 4)
    {
 
        char a[] = "1234";
        std::rotate(a, a + i, a + 4);
        std::cout << a  << " " ;
        std::next_permutation(a, a+ 4);
        std::cout << a << std::endl;
        ++i;
   } 
   i = 0;
   std::cout << std::endl;

 while(i < 9)
    {

        char a[] = "abcde1234";
        exercise::rotate<char *>(a, a + i, a + 9, exercise::bidirectionalIteratorTag());
        std::cout << a << "  ";
        exercise::next_permute<char *>(a, a+ 9,exercise::bidirectionalIteratorTag());
        std::cout << a << std::endl;
        ++i;
   }
#endif
   i = 0;
   while(i < 9)
    {

        char a[] = "abcde1234";
        exercise::rotate<char *>(a, a + i, a + strlen(a));
        std::cout << a << "  " << std::endl;
        ++i;
   }

    return 0;


}
