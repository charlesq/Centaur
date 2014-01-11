import java.util.StringTokenizer;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.IOException;
public class  Strtok
{
    public static void main(String []args) throws IOException
    {
        while(true)
        {
            String str;
            String delm;
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            System.out.println("provide target string:");             
            str = br.readLine();
            System.out.println("provide delimeter string:"); 
            delm = br.readLine();
            System.out.println();
            StringTokenizer st = new StringTokenizer(str, delm, false);  
            while(st.hasMoreTokens())
            {
                System.out.print(st.nextToken() + " ");
            }
            System.out.println();
            System.out.print("Exit(Y/N)?"); 
            str = br.readLine();
            if (str.equalsIgnoreCase("Y"))
                break;
        }
    }
}
