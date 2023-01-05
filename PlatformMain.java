import java.io.IOException;


import demo.DemoPlatform;
import ecomm.Platform;
import ecomm.Seller;
import demo.Seller1.Seller_1;
import demo.Seller2.Seller_2;
import demo.Seller3.Seller_3;
import java.util.*;

public class PlatformMain {

	public static void main(String[] args) throws IOException {
		
		Scanner sc = new Scanner(System.in);

		Platform pf = new DemoPlatform();  // replace with appropriate derived class
		
		// create a number of sellers (of different sub-types of Seller)
		// Assign a name (sellerID) to each of them.
		
		// replace each of the XYZ below with the derived class name of one of the
		// team members.
		
		
		Seller s1 = new Seller_1("Seller1"); 
		s1.addPlatform(pf);

		Seller s2 = new Seller_2("Seller2");
		s2.addPlatform(pf);
		
		Seller s3 = new Seller_3("Seller3");
		s3.addPlatform(pf);
 		
		
		while(true) {
			String input = sc.next();
			if(input.equals("Check")) {
				pf.processRequests();
			}
		}
		// keep reading from System.in
		// If "Check" typed in
		// invoke 
//			pf.processRequests();
		
			
	}

}
