package codeup;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a, b, c;
	    Scanner sc = new Scanner(System.in);
	    a = sc.nextInt();
	    b = sc.nextInt();
	    c = sc.nextInt();

	    // 비용이 가격보다 크거나 같으면 이익발생 불가 
	    if(b >= c)
	        System.out.printf("%d", -1);
	    else
	    	System.out.printf("%d", (a / (c - b) + 1));
	}
}