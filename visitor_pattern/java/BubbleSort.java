//package com.charlesq.java.visitorpattern;
import java.lang.Comparable;
/* a concrete element class in Visitor Pattern 
 */

public class BubbleSort <T extends Comparable<T>> implements Visitable<T>
{
   private transient T [] a;
   @Override
   public void accept(Visitor<T> v) 
   {
       v.visit(this);
   }
   public void init(T[] a)
   {
       this.a = a;
   }
   public void run()
   {
       for (int i = a.length -1; i != 0; --i)
           for (int j = 0; j < i; ++j)
               if (a[j].compareTo(a[j+1]) > 0)
                   swap(j, j + 1);
     
   }
   @Override
   public String toString()
   {
       return "Bubble Sort";
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
