/* Though many mehtods are available in java.util.Arrays.java, redo them as an exercise here */ 
import java.lang.Comparable;
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

}
