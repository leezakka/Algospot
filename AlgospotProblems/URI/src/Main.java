import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int pCount = sc.nextInt();
		
		// Special characters
		
		for(int i=0; i<pCount; i++)
		{
			// Main Process
			
			// Input Src String
			String src = sc.next();
			String dst = new String();
			
			dst = ConvertspCharToEncodedStr(src);

			dst = dst.replaceAll("\\#", "\\%");
			
			System.out.println(dst);
		}
		
		sc.close();
	}
	
	static String ConvertspCharToEncodedStr(String src)
	{	
		if(src.contains("%20"))
		{
			src = src.replaceAll("%20", "\\ ");
		}
		if(src.contains("%21"))
		{
			src = src.replaceAll("%21", "\\!");			
		}
		if(src.contains("%24"))
		{
			src = src.replaceAll("%24", "\\$");
		}		
		if(src.contains("%25"))
		{
			src = src.replaceAll("%25", "\\#");
		}		
		if(src.contains("%28"))
		{
			src = src.replaceAll("%28", "\\(");
		}		
		if(src.contains("%29"))
		{
			src = src.replaceAll("%29", "\\)");
		}	
		if(src.contains("%2a"))
		{
			src = src.replaceAll("%2a", "\\*");
		}	

		return src;
	}
}
