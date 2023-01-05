package demo;
import java.util.*;
import ecomm.Product;
public class NameSort implements Comparator<Product> {
	public int compare (Product p1,Product p2) {
		if(p1.getName().compareTo(p2.getName())==0) {
			
			return 0;
		}
	return p1.getName().compareTo(p2.getName());  
	}
}
