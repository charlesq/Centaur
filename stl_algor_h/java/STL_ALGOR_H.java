/* Though many mehtods are available in java.util.Arrays.java, redo them as an exercise here */ 
import java.lang.Comparable;
import java.util.Random;
public class STL_ALGOR_H
{
    public static <T> void swap(T[] a, int i, int j)
    {
        T t = a[i];
        a[i] = a[j];
        a[j] = t;  
    }
    public static <T> void reverse (T [] a, int s, int e)
    {
        while(s != --e && s < e)
            swap(a, s++, e);
    }
    public static <T> void rotate (T[] a, int m)
    {
       reverse(a, 0, a.length);
       reverse(a, 0, a.length - m);
       reverse(a, a.length - m, a.length);   
    }
    public static <T extends Comparable<T>> boolean next_permutation(T [] a)
    {
        if (a == null || a.length == 1)
            return false;
        int i = a.length - 1;
        do
        {
            if(a[i].compareTo(a[--i]) > 0)
               break;
            if (i == 0)
            {
                reverse(a, 0, a.length);
                return false;
            } 
        }while(true);
        int j = a.length;
        while(a[--j].compareTo(a[i]) <= 0); 
        swap(a, i, j);
        reverse(a, ++i, a.length); 
        return true;
    } 
    public static  <T> void shuffle (T[] a)
    {
        Random rand = new Random();    
        for (int i = 1; i < a.length; ++i)
        {
            int j = rand.nextInt(i + 1);
            swap(a, i, j);
        }
    }

}
