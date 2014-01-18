import org.junit.Test;


import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.JUnitCore; 
import org.junit.runner.Result;
import org.junit.runner.notification.Failure;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
public class  TestRunner
{
    @Test
    //@Ignore
    public void testSwap()
    {
        Object []a = new Object[5];
        for (int i = 0; i < a.length; ++i)
           a[i] = new Object();
        Object c = a[4], d = a[2];
        STL_ALGOR_H.swap(a,4, 2);
        assertEquals(a[4], d);
        assertEquals(a[2], c);
    }
    @Test
//    @Ignore
    public void testReverse()
    {
        Integer [] a = new Integer[20];
        for ( int i = 0; i < a.length; ++i)
           a[i] = new Integer(i); 
        STL_ALGOR_H.reverse(a, 0, 20);
        for (int i = 0; i < 20; ++i)
        {
            assertTrue("Failed", a[i].intValue() ==  a.length - 1 -i); 
        }
    }
    @Test
    public void testRotate()
    {
        Integer [] a = new Integer[5];
        for (int i = 1; i < a.length; ++i)
        {
            for (int k = 0; k < a.length; ++k)
                a[k] = new Integer(k);
            STL_ALGOR_H.rotate(a, i);
            
            for (int j = 0; j < a.length; ++j)
                System.out.print(a[j].toString() + " ");
            System.out.println();
            for (int j = 0; j < i; ++j)
            {
               if (j == a.length - i -1)
               {
                   assertTrue("failed", a[j] > a[j+1]);
                   continue;
               }
               assertTrue("failed", a[j] < a[j+1]); 
            }
        }
        
    }
    @Test
    public void testNextPermutation()
    {
       Integer [] a = new Integer[4];
       for (int i = 0; i < a.length; ++i)
           a[i] = new Integer(i);
       assertTrue(null, STL_ALGOR_H.next_permutation(a));  
       assertEquals(a[3], new Integer(2));
       for (int i = 0; i < a.length; ++i)
           a[i] = new Integer(a.length - i - 1);
       assertFalse(null, STL_ALGOR_H.next_permutation(a));
      
       
    }
    public static void main(String[] args)
    {
         Result result = JUnitCore.runClasses(TestRunner.class);
         for (Failure failure: result.getFailures())
             System.out.println(failure.toString());
    }
}
