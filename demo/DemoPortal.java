package demo;
import java.io.*;
//import ecomm.Product;
import java.util.*;

import ecomm.Portal;

public class DemoPortal extends Portal {
	public DemoPortal() throws IOException{
		requestID=0;
		Random random = new Random();    
		int x = random.nextInt(200); 
		portalID = "portal_"+x;
	}

public  void processUserCommand(String command) {
	
	FileWriter myWriter1 = null;
	PrintWriter out = null;
	try {
		myWriter1 = new FileWriter("./PortalToPlatform.txt", true);
	    BufferedWriter bw = new BufferedWriter(myWriter1);
	    out = new PrintWriter(bw);
	} catch (IOException e2) {
		// TODO Auto-generated catch block
		e2.printStackTrace();
	}
	
	String[] commands = command.split(" ");
	if(commands[0].equals("Start")) {
		out.println(portalID+" "+String.valueOf(requestID)+" "+commands[0]);
		commandMap.put(requestID, "Start");
	}
	else if(commands[0].equals("List")) {
	
	out.println(portalID+" "+String.valueOf(requestID)+" "+commands[0]+" "+commands[1]);
	sortOrder.put(requestID, commands[2]);
	commandMap.put(requestID,commands[0] );
	}
	else if(commands[0].equals("Buy")) {
		out.println(portalID+" "+String.valueOf(requestID)+" "+commands[0]+" "+commands[1]+" "+commands[2]);
		commandMap.put(requestID,commands[0]);
	}
	requestID++;
	out.close();
	
	
	
}
	
	
	public  void checkResponse() {
		String st;
		try {
			while((st=br.readLine())!=null) {
//				System.out.println(st);
				String data = st;
				String[] dataArray = data.split(" ");
				if(!dataArray[0].equals(portalID)) {
					continue;
				}
				if(commandMap.get(Integer.parseInt(dataArray[1])).equals("Start")){
					for(int i=2;i<dataArray.length;i++) {
						System.out.println(dataArray[i]);
					}
				}
				else if(commandMap.get(Integer.parseInt(dataArray[1])).equals("List")) {
					
					ArrayList<DerivedProduct> productList = new ArrayList<>();
						DerivedProduct dp = new DerivedProduct();
						dp.setName(dataArray[2]);
						dp.setProductID(dataArray[3]);
						dp.setPrice(Float.parseFloat(dataArray[4]));
						dp.setQuantity(Integer.parseInt(dataArray[5]));
						productList.add(dp);
//						System.out.println(dp.getName());
//						System.out.println(st);
						while((st=br.readLine())!=null) {
							DerivedProduct dp1 = new DerivedProduct();
//							System.out.println(st);
							String data1 = st;
							String[] dataArray1 = data1.split(" ");
//							System.out.println(dataArray1[2]);
							if(!dataArray[1].equals(dataArray1[1]) || !dataArray1[0].equals(portalID)) {
								break;
							}
							
								dp1.setName(dataArray1[2]);
								dp1.setProductID(dataArray1[3]);
								dp1.setPrice(Float.parseFloat(dataArray1[4]));
								dp1.setQuantity(Integer.parseInt(dataArray1[5]));
								productList.add(dp1);
//								System.out.println(dp1.getName());
							
						}
						if(sortOrder.get(Integer.parseInt(dataArray[1])).equals("Name")) {
							Collections.sort(productList, new NameSort());
						}
						else if(sortOrder.get(Integer.parseInt(dataArray[1])).equals("Price")) {
							Collections.sort(productList, new PriceSort());
						}
						for(DerivedProduct x : productList) {
							System.out.println(x.getName()+" "+x.getProductID()+" "+x.getPrice()+" "+x.getQuantity());
						}
						
					
				}
				
				
				else if(commandMap.get(Integer.parseInt(dataArray[1])).equals("Buy")) {
					System.out.println(dataArray[2]);
				}
			}
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

			}
	
	BufferedReader br
    = new BufferedReader(new FileReader("./PlatformToPortal.txt"));
	private String portalID ;
	private Integer requestID;
	private HashMap<Integer,String> sortOrder = new HashMap<>();
	private HashMap<Integer,String> commandMap = new HashMap<>();
	

}

