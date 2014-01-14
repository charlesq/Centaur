//package com.charlesq.java.visitorpattern;
import java.lang.Comparable;

/* a concrete Element for visitor pattern */

public class HeapSort<T extends Comparable<T>> implements Visitable<T>
{
    private transient T a[];
    @Override
    public void accept(Visitor<T> v)
    {
        v.visit(this);
    } 
    public void init(T []a)
    {
        this.a = a;
    }
  
    public void run()
    {
        /* produce a max heap */
        heapify(); 
        for (int i = a.length - 1; i != 0; --i)
        {
           swap(i, 0); 
           siftDown(0, i);
        }
    }
    /* recursive sift down procedure in heap sorting */
    private void siftDown(int i, int len)
    {
        int l = 2 * i + 1, r = l + 1; 
        if (l >= len)
            return;
        if (r < len)
        {
            l = a[l].compareTo(a[r]) >= 0? l: r;
        }
        if (a[i].compareTo(a[l]) >= 0)
            return; 
        swap(i, l);
        siftDown(l, len);
    }
    private void heapify()
    {
        for (int i = a.length / 2; i != -1; --i)
            siftDown(i, a.length); 
    }
    @Override
    public String toString()
    {
        return "Heap Sort";
    }
     /* A common utility method for sorting algorithm */
     void swap(int i, int j)
     {
         if (i == j)
             return;
         T temp = a[i];
         a[i] = a[j];
         a[j] = temp;
     }
}
