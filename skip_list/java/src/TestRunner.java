import org.junit.Test;
import org.junit.Ignore;
import org.junit.runner.JUnitCore;
import org.junit.runner.Result;
import static org.junit.Assert.assertEquals;
import static org.junit.Assert.assertTrue;
import static org.junit.Assert.assertFalse;
import org.junit.runner.notification.Failure;

public class TestRunner
{
     @Test
     public void testSkipList()
     {
         SkipList<Integer> sl = new SkipList<Integer>();
         sl.insert(1);
         sl.insert(3);
         sl.insert(-1);
         sl.insert(5);
         Node<Integer> [] r;  
         r = sl.getRoot();
         assertTrue(null, r[0].key.compareTo(-1) == 0);
         assertTrue(null, r[0].next[0].key.compareTo(1)==0);
         assertTrue(null, r[0].next[0].next[0].key.compareTo(3)==0);
         assertTrue(null, r[0].next[0].next[0].next[0].key.compareTo(5)==0);
         assertTrue(null, sl.search(-1));
         sl.remove(-1);
         assertFalse(null, sl.search(-1));
         
     }
     public static void main (String[] args)
     {
         Result result = JUnitCore.runClasses(TestRunner.class);
         for (Failure failure: result.getFailures())
             System.out.println(failure.toString());
     }
}
