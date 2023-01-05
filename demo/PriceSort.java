package demo;

import java.util.*;
import ecomm.Product;

public class PriceSort implements Comparator<Product>  {
	public int compare(Product p1,Product p2) {
		if(p1.getPrice() == p2.getPrice()) {
			return 0;
		}
		else if(p1.getPrice() > p2.getPrice()) return 1;
		else return -1;
	}
}
