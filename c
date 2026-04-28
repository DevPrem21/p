import java.util.*;

public class Load {

    static void printLoad(int servers, int processes) {

        if (servers <= 0) {
            System.out.println("No servers available!");
            return;
        }

        int each = processes / servers;
        int extra = processes % servers;

        int i = 0;

        for (i = 0; i < extra; i++) {
            System.out.println("Server " + (i + 1) + " has " + (each + 1) + " Processes");
        }

        for (; i < servers; i++) {
            System.out.println("Server " + (i + 1) + " has " + each + " Processes");
        }
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of Servers: ");
        int servers = sc.nextInt();

        System.out.print("Enter the number of Processes: ");
        int processes = sc.nextInt();

        while (true) {

            System.out.println("\n--- Current Load Distribution ---");
            printLoad(servers, processes);

            System.out.println("\n1. Add Servers");
            System.out.println("2. Remove Servers");
            System.out.println("3. Add Processes");
            System.out.println("4. Remove Processes");
            System.out.println("5. Exit");

            int choice = sc.nextInt();

            switch (choice) {

                case 1:
                    System.out.print("How many servers to add? ");
                    servers += sc.nextInt();
                    break;

                case 2:
                    System.out.print("How many servers to remove? ");
                    servers -= sc.nextInt();
                    if (servers < 1) {
                        System.out.println("Servers cannot be less than 1!");
                        servers = 1;
                    }
                    break;

                case 3:
                    System.out.print("How many processes to add? ");
                    processes += sc.nextInt();
                    break;

                case 4:
                    System.out.print("How many processes to remove? ");
                    processes -= sc.nextInt();
                    if (processes < 0) {
                        System.out.println("Processes cannot be negative!");
                        processes = 0;
                    }
                    break;

                case 5:
                    System.out.println("Exiting...");
                    sc.close();
                    return;

                default:
                    System.out.println("Invalid choice!");
            }
        }
    }
}
