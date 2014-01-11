import java.lang.Exception;
import java.lang.IndexOutOfBoundsException;
public class Permute
{
    private static int c = 0;
    public static void swap(char []a, int i, int j) throws IndexOutOfBoundsException
    {

        if (i > a.length -1 || j > a.length -1)
            throw new IndexOutOfBoundsException();

        char t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    public static void permute_t(char [] a, int index)
    {
        /* reject */
        if (a  == null || index > a.length)
            return;
        /* accept */
        if (index == a.length)
        {
            String p = new String(a) + " ";
            System.out.print(p);
            if (++c % 10 == 0)
                System.out.println();
            return;
        }
        /* extend the candidate partial solution tree */
        for (int i = index; i < a.length; ++i)
        {
           try
           {
               swap(a, index, i);
               permute_t(a, index +1);
               swap(a, index, i); 
          }

          catch(IndexOutOfBoundsException e)
          {
              return;
          }

        }
    } 
    public static void main(String [] args)
    {
        String s = new String("abc");
        char []str = s.toCharArray(); 
        Permute.permute_t(str, 0);
        System.out.println();
    }
}
