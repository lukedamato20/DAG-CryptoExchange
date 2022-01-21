public class RequestApproval extends OrderBook
{
    int traderId;

    public void setTraderId(int traderId) {
        this.traderId = traderId;
    }

    public int getTraderId() {
        return traderId;
    }
}