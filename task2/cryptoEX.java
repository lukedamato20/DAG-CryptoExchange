import java.util.Scanner;

public class cryptoEX
{
    public static void main(String[] args)
    {
        Scanner userinput = new Scanner (System.in);

        System.out.println("Crypto Exchange. \nYour name: ");
        String userName = userinput.nextLine();

        System.out.println("Welcome " + userName);

        userinput.close();
    }
}