public class RequestSell extends OrderBook
{
    String sellId;

    // getting and setting order id
    public void setSellId(String sellId) {
        this.sellId = sellId;
    }

    public String getSellId() {
        return sellId;
    }
}