import java.util.ArrayList;
import java.util.List;
import java.util.Iterator;
public class Kosaraju
{
    final Graph g;
    private Graph tg;/* transposed graph */
    List <Integer> discSeq; /* store vertice in DFS discovery sequence */
    class StoreDfsSequence implements Action
    {
        List<Integer> seq; /* store vertice in DFS discovery squence */ 
        public void act(int v)
        {
            seq.add(v);
        }
        public StoreDfsSequence (List<Integer> seq)
        {
            this.seq = seq;
            
        }
    }
    class PrintAction implements Action
    {
        final Graph g;
        List<Integer> scc;
        final int [] color;
        public void act(int v)
        {
            List<Edge> adj = g.Adj(v);
            Iterator<Edge> it = adj.iterator();
            while(it.hasNext())
            {
                if(color[it.next().o()] ==0)
                {
                    scc.add(v);
                    return;
                }
            }
            scc.add(v);
            Iterator<Integer>  it1 = scc.iterator();
            System.out.print("(");
            while (it1.hasNext())
            {
                System.out.print(it1.next());
                System.out.print(" ");
            }
            System.out.print(")");
            System.out.println();
            scc.clear();
        }
        public PrintAction(Graph g, int [] c)
        {
            this.g = g;
            this.color = c;
            scc = new ArrayList<Integer>();
        }
   
    }
    public Kosaraju (final Graph g)
    {
        this.g = g;
        tg = new Graph(g, true);
        discSeq = new ArrayList<Integer>(); 
    }
    public void run()
    {
        /* init actions */
        discSeq.clear();      
        /* conduct the first round of DFS */
        DFS dfs = new DFS(g);
        dfs.setDiscoveredAction(new StoreDfsSequence(discSeq));
        for (int i = 0; i < g.V(); ++i)
             dfs.search(i);
        /* conduct the second round of DFS on the transposed graph */
        dfs = new DFS(tg);
        dfs.setDiscoveredAction(new PrintAction(tg, dfs.color()));
        Iterator<Integer> it = discSeq.iterator();
        while(it.hasNext())
        {
            dfs.search(it.next());
        }
    }
}
