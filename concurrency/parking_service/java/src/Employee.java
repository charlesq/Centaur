//package com.charles.java.parking;
public class Employee extends Entity
{
    public Pager pager; 
    private  boolean onDuty;
    public final String name;// Added name later !!! 
    private ParkingService firm;
    public Employee (int id)
    {
        super(id);
        onDuty = false;
        name = "anonymous";
        this.firm = ParkingService.getService();
    }
    synchronized void signIn()
    {
        onDuty = true;
        pager = firm.getPager();
        pager.setCarrier(this);
        
    } 
    synchronized void signOff()
    {
        pager.setCarrier(null);
        firm.returnPager(pager);
        onDuty = false;
        pager = null;
    }
}
