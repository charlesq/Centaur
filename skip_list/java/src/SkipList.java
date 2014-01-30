import java.util.Arrays;
import java.util.Random;
import java.lang.Comparable;
import java.lang.Integer;
import java.util.concurrent.locks.ReentrantReadWriteLock;
public class SkipList <T extends Comparable<T>>
{
    private final int maxLevel;
    /* for indexing purpose, linked list at each level/subsequence must have a head */
    private Node<T> [] root; 
    /* curr and prev are used in insertion operation */
    private transient Node<T> [] curr;
    private transient Node<T> [] prev;
   /* the rand function to determine presence level for a node */
    private Random rand;
    private static final int defaultLevels = 4;
    private ReentrantReadWriteLock rwlock; // to secure concurrent access 
    @SuppressWarnings({"unchecked", "rawtypes"})
    public SkipList(int maxLevel)
    {
        this.maxLevel = maxLevel;
        root = new Node[maxLevel];
        Arrays.fill(root, null);
        curr = new Node [maxLevel];
        Arrays.fill(curr, null);
        prev = new Node  [maxLevel];
        Arrays.fill(prev, null);
        rand = new Random();
        rwlock = new ReentrantReadWriteLock();
    }
    public SkipList()
    {
        this(defaultLevels);
    }
    public  void remove(T k)
    {
            rwlock.writeLock().lock();
            int level = maxLevel -1;
            Arrays.fill(prev, null);
            Arrays.fill(curr, null);
            curr[level] = root[level];
            prev[level] = null; 
            while(level>= 0)
            {
                if (prev[level] == curr[level] && curr[level] == null)
                {
                    curr[level -1] = root[level -1];
                    prev[--level] = null;
                    continue;
                }
                if (k.compareTo(curr[level].key) == 0)
                {
                      /* remove curr from the sequence in the current layer */
                      if (level != 0)
                      {
                          if (prev[level] == null)
                          {
                              root[level] = curr[level].next[level-1];
                              curr[level -1] = curr[level--];
                              continue;
                          } 
                          if (prev[level].next[level -1] != curr[level])
                          { 
                              prev[level-1] = prev[level].next[level -1];
                              curr[level-1] = curr[level--];
                              continue;
                          }
                          prev[level].next[level] = curr[level].next[level];
                          prev[level-1] = prev[level];
                          curr[level-1] = curr[level--];
                          continue;
                      }
                      if (prev[level] == null)
                      {
                          root[level] = curr[level].next[level];
                      }
                      else
                          prev[level].next[level] = curr[level].next[level];
                      break;
                }
                if (k.compareTo(curr[level].key) > 0)
                {
                    prev[level] = curr[level];
                    if (curr[level].next[level] == null)
                    {
                        curr[level] = curr[level].next[--level];
                        continue; 
                    }
                    curr[level] = curr[level].next[level];
                    continue;
                }
                if (curr[level] == root[level])
                    curr[level -1] = root[--level]; 
                else
                {
                   curr[level-1] = prev[level].next[level -1];
                   prev[level-1] = prev[level--];
                 }
            }
            /* reset curr and prev so the removed node is eligible for gabage collection */
            Arrays.fill(curr, null);
            Arrays.fill(prev, null);
            rwlock.writeLock().unlock();
        return; 
    }
    public void removeAll()
    {
             
             Arrays.fill(root, null);
    }
    public boolean isEmpty()
    {
        return root[0] == null;
    }
    private int generateRandomizedLevel()
    {
        int i = 0, j =1, r = rand.nextInt(Integer.MAX_VALUE);
        while( ++i < maxLevel && r <= Integer.MAX_VALUE / j )
        {
            j <<= 1; 
        }
        return i;
    }
    private void addNode(T k)
    {
        int level = generateRandomizedLevel();
        Node <T> node = new Node<T>(k, level);
        for (int i = 0; i < level; ++i)
        {
            node.next[i] = curr[i];
            /* if head of the subquence is null, make this node the head */
            if (prev[i] == null )
                root[i] = node;
            else
               prev[i].next[i] = node;
            
             
        }
    }
    public boolean insert(T k)
    {
        boolean newElem = true;
        rwlock.writeLock().lock();
        {
            Arrays.fill(curr, null);
            Arrays.fill(prev, null);
            curr[maxLevel -1] = root[maxLevel-1];
            prev[maxLevel-1] = null;
            newElem =  insert(k, maxLevel -1);
         }
         rwlock.writeLock().unlock();
         return newElem;
    }

    /* Before inserting a new key, the consecutive nodes, i.e. pre and cur nodes at each level 
       of subseuqnce must be determined.
       To do that, we start from the top level, identify the pre and cur node pair at the top;
       then drop down to the next level, do the same; until it reaches the bottom level 
       subsequence. The curr and prev at each layer must be preserved. 
       
       That being done, we can insert a new node with the key at the bottom level; thereafter
       choose a level value and make sure the pre's next node and the new node's next node are 
       properly set at each level up to  the chosen level. 
     */ 
    private boolean insert(T k, int level)
    {
        if (level > 0)
        {
           /* set the prev and curr to be considered for the sub 
              sequence one layer below */
           
           /* reached tail in the current layer */
           if (curr[level] == null)
           {
               /* this layer has no node, move to the head of next layer  */
               if (prev[level] == null)
               {
                   curr[level -1] = root[level -1]; 
                   prev[--level] = null;
               }
               else
               {
                   /* curr[level-1] falls back to prev[level].next[level-1]
                      for the time being */ 
                   if (prev[level].next[level-1] != null)
                   {
                       curr[level-1] = prev[level].next[--level];
                   }
                   else
                   {
                       curr[level -1] = prev[level].next[level -1];
                       prev[level -1] = prev[level--];
                   }
               }
            }
            else
            {
                /* case of key already in the skip list */
                if (k.compareTo(curr[level].key) == 0)
                    return false;
                /* case of  k is bigger than key element at  curr[level], 
                  move pre and curr next node at the
                  layer of  subsequence */
                if (k.compareTo(curr[level].key) > 0)
                {
                    prev[level] = curr[level];
                    curr[level] = curr[level].next[level];
                }
                else
                {
                   if ( prev[level] != null && prev[level].next[level-1] != curr[level])
                   {
                       curr[level-1] = prev[level].next[level -1];
                       prev[level -1] = prev[--level];
                    
                   }
                   else
                   {
                       prev[level -1] = prev[level];
                       curr[level -1] = curr[level--]; 
                   }
                }
            }
            return insert(k, level);
        }
        /* reached bottom layer */
        addNode(k);
        return true;
    }
    public boolean search(T k)
    {
        rwlock.readLock().lock();
        int level = maxLevel;
        boolean found = false;
        Node <T> p = null, c = p; // prev and cur node at current layer */  
        while (level > 0)
        {
             if (c == null && p == null)
             {
                 c = root[--level];
                 p = null;
                 continue;
             }
             if (c == null)
             {
                 c = p.next[--level];
             }
             if (k.compareTo(c.key) == 0)
             {
                 found = true;
                 break;
             }
              if (k.compareTo(c.key) > 0)
              {
                  p = c;
                  if (c.next[level] != null)
                  {
                      c = c.next[level]; 
                      continue;
                  }
                  c = c.next[--level];
                  continue;
              }
              if (c == root[level])
                  c = root[--level];
              else
                  c = p.next[--level];
        }
        rwlock.readLock().unlock();
        return found;
    }
    /* this method is for testing purpose */
    Node <T> [] getRoot()
    {
        return root;
    }
}
