//package com.charles.java.parking;
public class Employee extends Entity
{
    public Pager pager; 
    private  boolean onDuty;
    public final String name;// Added name later !!! 
    private ParkingService firm;
    public Employee (int id, ParkingService service)
    {
        super(id);
        onDuty = false;
        name = "anonymous";
        this.firm = service;
    }
     
    synchronized void onShift()
    {
        onDuty = true;
    } 
    synchronized void offDuty()
    {
        returnPager();
        onDuty = false;
    }
    private void returnPager()
    {
    }
    private void getPager()
    {
    }
}
