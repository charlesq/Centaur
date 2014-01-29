import java.util.Arrays;
class Node <T>
{
    T key;
    Node<T> [] next;
    @SuppressWarnings({"unchecked", "rawtypes"})
    Node(T key, int n)
    {
        this.key = key;
        next = new Node[n];
        Arrays.fill(next, null);
    }
    
}

