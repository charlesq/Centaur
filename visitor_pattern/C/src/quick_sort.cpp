#include <inc/quick_sort.h>
#include <algorithm>
#include <cstdlib>
template<typename T, typename C>
size_t quick_sort<T,C>::partition(size_t s, size_t e)
{
    C c;
    /* a[s] is the pivot element */
    size_t i = s, j = s;   
    while(++j < e)
    {
        if (c(a[s],a[j]))
            continue; 
        std::swap(a[++i], a[j]);
    }
    std::swap(a[i], a[s]);
    return i;
}
template<typename T, typename C>
void quick_sort<T,C>::sort(size_t s,  size_t e)
{
    if (s + 1 >= e)
        return;
    /* randomize pivot element */
    size_t p = rand() % ( e - s) + s;
    std::swap(a[p], a[0]);
    p = partition(s,e);
    quick_sort(s, p);
    quick_sort(p + 1, e);
}
template<typename T, typename C>
void quick_sort<T,C>::do_work(void)
{
    sort(0, sz);
}
