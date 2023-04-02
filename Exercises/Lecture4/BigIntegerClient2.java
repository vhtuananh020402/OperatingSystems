import java.io.*;
import java.net.Socket;

public class BigIntegerClient2 {
    private static String clientName = "Client 2";

    public static void main(String[] args) {
        try {
            /* make connection to server socket */
            Socket sock = new Socket("127.0.0.1", 6014);

            /* send the client name to the server */
            PrintWriter out = new PrintWriter(sock.getOutputStream(), true);
            out.println(clientName);

            InputStream in = sock.getInputStream();
            BufferedReader bin = new BufferedReader(new InputStreamReader(in));

            /* read the date from the socket */
            String line;
            while ((line = bin.readLine()) != null)
                System.out.println(line);
            /* close the socket connection */
            sock.close();

        } catch (IOException ioe) {
            System.err.println(ioe);
        }
    }
}
