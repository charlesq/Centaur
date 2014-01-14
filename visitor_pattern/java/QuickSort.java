//package com.charlesq.java.visitorpattern;
import java.util.Random;
import java.lang.Object;
import java.lang.Comparable;
public class QuickSort<T extends Comparable<T>> implements Visitable<T>
{
     private transient T[] a;
     @Override
     public void  accept(Visitor<T> v)
     {
         v.visit(this);
     }    
     public void init(T [] a)
     {
         this.a = a;
     }
     public void run()
     {
         sort(0, a.length);
     }
     
     /* partition elements in [s, e) */
     private int partition(int s, int e)
     {
        int i = s, j = s;  
        while(++j < e)
        {
     
            if (a[s].compareTo(a[j]) >= 0) 
                swap(++i, j);
        }
        swap(i, s);
        return i;
     }
     public void sort(int s, int e)
     {
         /* termination condition in recusive call, 
            minimal two elements are required */
         if (s + 1 >= e)
             return;
         /* pick a random pivot element */
         int p = (new Random()).nextInt(e-s) + s; 
         swap(p, s);/* start element is the pivot */
         p = partition(s,e);
         sort(s, p); 
         sort(p + 1, e);
     }
     public String toString()
     {
         return "Quick Sort";
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
