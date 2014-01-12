#include <inc/heap_sort.h>
#include <algorithm>

template<typename T, typename C>
void heap_sort<T,C>::sift_down(size_t idx, size_t size)
{
    C c;
    size_t l = idx * 2 + 1, r = l + 1;
    if (l >= size)
        return;
    if (r < size)
        l = c(a[l], a[r])?r:l;
    if (!c(a[idx], a[l]))
        return;
    std::swap(a[idx], a[l]);
    sift_down(l, size);
}
template<typename T, typename C>
void heap_sort<T,C>::heapify(void)
{
    for (size_t i = sz / 2; i != -1; --i)
    {
        sift_down(i, sz);
    }
}
template<typename T, typename C>
void heap_sort<T,C>::do_work(void)
{ 
    heapify();
    for (int i = sz -1; i != 0; --i)
    {
        std::swap(a[0], a[i]);
        sift_down(0, i);
    }
}
