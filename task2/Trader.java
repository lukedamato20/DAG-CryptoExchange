import java.util.ArrayList;

public class Trader extends User 
{
    public Trader(String id, String name, String surname, String occupation, String gender) 
    {
        super(id, name, surname, occupation, gender);
    }

    // Account type: Trader
    // Permissions:
    // - register
    // (after approval)
    // - BUY orders
    // - SELL orders

    ArrayList<OrderBook> requests = new ArrayList<OrderBook>();

    // request admin for approval
    void requestApproval()
    {
        RequestApproval reqApproval = new RequestApproval();
        requests.add(reqApproval);
    } 

    // request to system to buy an order
    void requestBuy()
    {

    }

    // request to system to sell an order
    void requestSell()
    {

    }
    
}