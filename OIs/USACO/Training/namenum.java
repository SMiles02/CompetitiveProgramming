/*
 ID: mahajan6
 LANG: JAVA
 TASK: namenum
 */

import java.util.*;
import java.io.*;

public class namenum {
	
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("namenum.in"));
		BufferedReader br = new BufferedReader(new FileReader("dict.txt"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("namenum.out")));
		  
		ArrayList <String> solution = new ArrayList <String> ();
		String s = read.readLine();
		String st;
		while((st = br.readLine()) != null) {
			String ss = Stringvalue(st);
			if(ss.equals(s))
				solution.add(st);
			// st = br.readLine();
		}
		
		Collections.sort(solution);
		
		if(solution.isEmpty()) {
			pw.println("NONE");
		}
		
		else {
			for(String a: solution) {
				pw.println(a);
			}
		}
	
		pw.close();
		System.exit(0);
		
	}
	
	public static String Stringvalue(String s) {
		String c = "";
		for(int i = 0; i < s.length(); i++) {
			c += letterValue(s.charAt(i));
		}
		
		return c;
	}
	
	public static int letterValue(char c) {
		String s = c + "";
		if(s.matches("[A-C]")) return 2;
		else if(s.matches("[D-F]")) return 3;
		else if(s.matches("[G-I]")) return 4;
		else if(s.matches("[J-L]")) return 5;
		else if(s.matches("[M-O]")) return 6;
		else if(s.matches("[P-S]")) return 7;
		else if(s.matches("[T-V]")) return 8;
		else return 9;
			
	}

}