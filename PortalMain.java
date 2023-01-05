import java.io.IOException;
import java.util.*;
import demo.DemoPortal;
import ecomm.Portal;
public class PortalMain {

	public static void main(String[] args) throws IOException {
		
		Portal pr = new DemoPortal();
		Scanner sc = new Scanner(System.in);
		while(true) {
			String command = sc.nextLine();
			String[] c = command.split(" ");
			if(c[0].equals("Check")) {
				
				pr.checkResponse();
				
			}
			else {
				pr.processUserCommand(command);
			}
		}
		

	}
}
