//package com.charlesq.java.visitorpattern;
import java.lang.Comparable;
/* a concrete element for Visitor Pattern */
public class InsertSort<T extends Comparable<T>> implements Visitable<T>
{
    private transient T []a;
    @Override
    public void accept (Visitor<T> v)
    {
        v.visit(this);
    }
    public void init(T[] a)
    {
        this.a = a;
    }
    public void run()
    {
        for (int i = 1; i < a.length; ++i)
            for (int j = i; j != 0; --j)
                if (a[j].compareTo(a[j-1]) < 0)
                {
                    swap(j, j -1);
                }
    }
    @Override
    public String toString()
    {
        return "Insert Sort";
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
