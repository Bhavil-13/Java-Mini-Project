package demo;
import ecomm.Globals;
import ecomm.Product;
public class DerivedProduct extends Product {
	
	private int quantity;
	private float price;
	private String productId;
	private String name;
	private Globals.Category category;
	
	public  Globals.Category getCategory(){
		return category;
	}
	
	
	public String getName() {
		return name;
	}
	public void setName(String n) {
		name = n;
	}
	
	
	public String getProductID() {
		return productId;
	}
	public void setProductID(String p) {
		productId = p;
	}
	
	
	public float getPrice() {
		return price;
	}
	public void setPrice(float p) {
		price = p;
	}
	
	
	public int getQuantity() {
		return quantity;
	}
	public void setQuantity(int q) {
		quantity=q;
	}
	
	
	

}
