//package com.charles.java.parking;
import java.util.concurrent.Callable;
/* Notes:  
   1. once generated, the recipient and sender are unchangeable 
      and only sender may act on the message.     
   2. make it callable, so a message itself specifies action on it,
      no parsing is required in the dispatch class,
      we move it to the Entity object; 
      
      The Message is contract between the recipient and sender entity.  
*/  
public abstract class Message implements Callable<Boolean>
{
    private final int what;
    private Entity from; 
    private Entity to;
    public Message(int what, Entity from, Entity to)
    {
        this.what = what;
        this.from = from;
        this.to = to;
    }
    final Entity getFrom()
    {
        return from;
    } 
    final Entity getTo()
    {
        return to;
    } 
}
