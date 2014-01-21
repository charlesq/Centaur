import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import org.junit.runner.notification.Failure;
import java.util.Iterator;
import java.util.Collections;

public class TestRunner
{
    @Test
    public void testAddAndIterator()
    {
        SinglyLinkedList<Integer> lst = new SinglyLinkedList<Integer>();        
        int [] values = {1, 20, 4};
        for (int v: values)
            lst.add(new Integer(v));
        Iterator<Integer> itr = lst.iterator(); 
        int i = 0;
        while(itr.hasNext())
        {
             assertTrue(null, Integer.valueOf(itr.next()) == values[values.length - ++i]);
            
        }
    }
    @Test
    public void testMergeSort()
    {
        SinglyLinkedList<Integer> lst = new SinglyLinkedList<Integer>();
        int [] values = {1, 20,4};
        for (int v: values)
            lst.add(new Integer(v));
        lst.mergeSort();
        Iterator<Integer> itr = lst.iterator();
        Integer v = itr.next(); 
        while(itr.hasNext())
        {
           Integer vv = itr.next(); 
           assertTrue(null, vv.compareTo(v) >= 0);
           v = vv;
        }
           
    } 
    public static void main(String [] args)
    {
        Result result = JUnitCore.runClasses(TestRunner.class);
        for (Failure failure: result.getFailures())
            System.out.println(failure.toString());
    }
}
