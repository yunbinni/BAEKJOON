package codeup;

import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		int a, b, c;
	    Scanner sc = new Scanner(System.in);
	    a = sc.nextInt();
	    b = sc.nextInt();
	    c = sc.nextInt();

	    // ����� ���ݺ��� ũ�ų� ������ ���͹߻� �Ұ� 
	    if(b >= c)
	        System.out.printf("%d", -1);
	    else
	    	System.out.printf("%d", (a / (c - b) + 1));
	}
}