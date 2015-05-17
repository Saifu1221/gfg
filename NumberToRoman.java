class NumberToRoman{
	String huns[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"}; 	    
    String tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"}; 	    
    String ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"}; 	     	    
    int   size[] = {0,   1,    2,     3,    2,   1,  2,      3,       4,     2};
	
	public String convertToRoman(int val){
		String res = "";
		if(val >= 1000){
			res = res + 'M';
			val = val -1000;
		}
		
		res += huns[val/100];
		val = val%100;
		res += tens[val/10];
		val = val%10;
		res +=ones[val];
		
		return res;
		
	}
	
	public static void main(String arg[]){
		NumberToRoman nr = new NumberToRoman();
		System.out.println("\nRoman correspoding to 25 is : "+nr.convertToRoman(25));
		System.out.println("\nRoman correspoding to 100 is : "+nr.convertToRoman(100));
		System.out.println("\nRoman correspoding to 101 is : "+nr.convertToRoman(101));


	}
}