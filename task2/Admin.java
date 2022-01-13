public class Admin extends User 
{
    public Admin(String id, String name, String surname, String occupation, String gender) 
    {
        super(id, name, surname, occupation, gender);
    }

    // Account type: ADMIN

    // Approval for trading
    void approveBuy(RequestBuy request)
    {
        request.approved = true;
    }

    void approveSell(RequestSell request)
    {
        request.approved = true;
    }
}