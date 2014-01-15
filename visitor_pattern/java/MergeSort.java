//package com.charlesq.java.visitorpattern;
import java.lang.Comparable;
import java.lang.Class;
import java.lang.reflect.Array;
import java.util.Arrays;
/* a concrete element in visitor pattern */
public class MergeSort<T extends Comparable<T>> implements Visitable<T>
{
    private transient T [] b;
    private transient T[] a;
    @Override
    public void accept (Visitor<T> v)
    {
       v.visit(this); 
    }
    public void init(T [] a)
    {
        this.a = a;
    }
    public void run()
    {
        b  = ( T[])Array.newInstance(a.getClass().getComponentType(), a.length);
        divide(0, a.length);
    }
    @Override
    public String toString()
    {
        return "Merge Sort";
    }
    private void divide(int s, int e)
    {
        /* termination condition in recursive divide */
        if (s +1 >= e)
            return;
         divide(s, (s+e)>>>1);
         divide ((s+e)>>>1, e);
         merge(s, e);
    }
    private void merge(int s, int e)
    {
        int m = (s + e) >>> 1, i = s, j = m, k = 0;
        while(i < m && j < e)
            b[k++] = (a[i].compareTo(a[j]) <= 0)? a[i++]: a[j++];
        while(i < m)
            b[k++] = a[i++];
        while(j < e)
            b[k++] = a[j++];
        while (k-- != 0)
            a[--e] = b[k];
    }
}

 
