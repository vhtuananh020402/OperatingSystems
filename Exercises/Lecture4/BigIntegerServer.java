import java.io.*;
import java.math.BigInteger;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.Random;

public class BigIntegerServer {

    public static void main(String[] args) {
        try {
            ServerSocket sock = new ServerSocket(6014);

            /* now listen for connections */
            while (true) {
                Socket client = sock.accept();
                /* print out the name of the client */
                BufferedReader in = new BufferedReader(new InputStreamReader(client.getInputStream()));
                String clientName = in.readLine();
                System.out.println("Client name: " + clientName);

                PrintWriter pout = new PrintWriter(client.getOutputStream(), true);

                /* write the date from the socket */
                pout.println(new java.util.Date().toString());

                /* write the BigInteger from the socket */
                pout.println(generateRandomBigInteger());

                /* close the socket and resume */
                /* listening for connections */
                client.close();
            }

        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }

    public static BigInteger generateRandomBigInteger() {
        BigInteger maxLimit = new BigInteger("5000000000000");
        BigInteger minLimit = new BigInteger("25000000000");
        BigInteger bigInteger = maxLimit.subtract(minLimit);
        Random randNum = new Random();
        int len = maxLimit.bitLength();
        BigInteger res = new BigInteger(len, randNum);
        if (res.compareTo(minLimit) < 0)
            res = res.add(minLimit);
        if (res.compareTo(bigInteger) >= 0)
            res = res.mod(bigInteger).add(minLimit);
        return res;
    }
}
