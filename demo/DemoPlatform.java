package demo;

import java.io.*;
import ecomm.Platform;
import ecomm.Seller;
import ecomm.Globals;
import ecomm.Product;
import java.util.*;




public class DemoPlatform extends Platform {
	
	
	
	public DemoPlatform() throws IOException {

	}

	@Override
	public boolean addSeller(Seller aSeller) {
		sellerList.add(aSeller);
		return false;
	}

	@Override
	public void processRequests()  {
		FileWriter myWriter = null;
		PrintWriter out = null;
		try {
			myWriter = new FileWriter("./PlatformToPortal.txt", true);
		    BufferedWriter bw = new BufferedWriter(myWriter);
		    out = new PrintWriter(bw);
		} catch (IOException e2) {
			// TODO Auto-generated catch block
			e2.printStackTrace();
		}
		String st;
	      try {
			while ((st = br.readLine()) != null) {
				
				  
			    String data = st;
				String[] dataArray = data.split(" ");
						
						
						  
						
			    if(dataArray[2].equals("Start")){
			    	
			    	
			    	
			    	out.print(dataArray[0]+" "+dataArray[1]+" ");
							for(Globals.Category x : Globals.Category.values()){
								out.print(x+" ");
							}
							out.println(" ");
						}
			    else if(dataArray[2].equals("List")) {
			    	for(Seller x : sellerList) {
			    		for(Product t : x.findProducts(Globals.Category.valueOf(dataArray[3]))){
			    			out.println(dataArray[0]+" "+dataArray[1]+" "+t.getName()+" "+t.getProductID()+" "+t.getPrice()+" "+t.getQuantity());
			    		}
			    	}
			    }
			    else if(dataArray[2].equals("Buy")) {
			    	for(Seller x : sellerList) {
			    		for(Product t : x.findProducts(Globals.Category.Mobile)) {
			    			if(t.getProductID().equals(dataArray[3])) {
			    				if(x.buyProduct(dataArray[3],Integer.parseInt(dataArray[4]))) {
			    					out.println(dataArray[0]+" "+dataArray[1]+" "+"Success");
			    					break;
			    				}
			    				else {
			    					out.println(dataArray[0]+" "+dataArray[1]+" "+"Failure");
			    					break;
			    				}
			    			}
			    		}
			    		
			    		for(Product t : x.findProducts(Globals.Category.Book)) {
			    			if(t.getProductID().equals(dataArray[3])) {
			    				if(x.buyProduct(dataArray[3],Integer.parseInt(dataArray[4]))) {
			    					out.println(dataArray[0]+" "+dataArray[1]+" "+"Success");
			    				}
			    				else {
			    					out.println(dataArray[0]+" "+dataArray[1]+" "+"Failure");
			    				}
			    			}
			    		}
			    	}
			    	
			    }
}
		} catch (IOException e1) {
			// TODO Auto-generated catch block
			e1.printStackTrace();
		}
out.close();
	      
	   
	      
	     
	
}

	private ArrayList<Seller> sellerList = new ArrayList<>();
	
//	private File myObj = new File("/home/muteeb/PortalToPlatform.txt");
//	private Scanner myReader = new Scanner(myObj);
	BufferedReader br
    = new BufferedReader(new FileReader("./PortalToPlatform.txt"));
	


}
