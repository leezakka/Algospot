import java.util.Scanner;

public class Main 
{	
	public static void main(String[] args) 
	{
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int nCount = 0;
		// Set Program count
		nCount = sc.nextInt();
		
		
		// Initialize Dst StringBuilder
		StringBuilder[] dst = new StringBuilder[nCount];
		for(int i=0; i<nCount;i++)
		{
			dst[i] = new StringBuilder();
		}
				
		
		for(int i=0; i<nCount; i++)
		{			
			
			// get Misspell Num and sourceString
			String sSrc = new String();
			String sMispell = new String();
		
			sMispell = sc.next();
			sSrc = sc.next();
			
			int nMispell = Integer.parseInt(sMispell);
			
			// Main Processing
			String sTemp1 = sSrc.substring(0,nMispell-1);
			String sTemp2 = sSrc.substring(nMispell, sSrc.length());
			
			StringBuilder tempDst = new StringBuilder();
			
			tempDst.append(sTemp1);
			tempDst.append(sTemp2);
			
			dst[i] = tempDst;
						
		}
		
		// Print Results
		for(int i=0; i<nCount; i++)
		{
			System.out.print(i+1 + " " + dst[i] + "\n");
		}
		
		sc.close();
	}
}