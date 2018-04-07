import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		// TestCase var
		int T = 0;
		Scanner sc = new Scanner(System.in);

		// Error Check
		try
		{
			// Set TestCase Count
			T = sc.nextInt();

			if(T < 0 || T > 10)
			{
				throw new Exception("Overflow");
			}
		}
		catch (Exception e)
		{
			String str = e.getMessage();
			System.err.println(str);
			System.exit(0);
		}
		
		// Initialize StringBuilder
		StringBuilder[] dst = new StringBuilder[T];
		for(int i=0; i<T;i++)
		{
			dst[i] = new StringBuilder();
		}

		// Main Process
		for(int i=0; i<T; i++)
		{
			// Set String
			String src = new String();
			src = sc.next();
			
			Encrypt en = new Encrypt();
			
			dst[i] = en.EncryptString(src);
		}
		
		// Print result
		for(int i=0; i<T; i++)
		System.out.println(dst[i]);

		sc.close();	
	}
}

class Encrypt
{
	private String tempDst1;
	private String tempDst2;
	private StringBuilder dst;
	
	Encrypt()
	{
		tempDst1 = new String();
		tempDst2 = new String();
		dst = new StringBuilder();
	}

	public StringBuilder EncryptString(String src)
	{
		for(int i=0; i<src.length();i++)
		{
			if(i%2 == 0)
				this.tempDst1 = this.tempDst1.concat(src.valueOf(src.charAt(i)));
			else
				this.tempDst2 = this.tempDst2.concat(src.valueOf(src.charAt(i)));
		}
	
		dst.append(this.tempDst1);
		dst.append(this.tempDst2);
		return dst;
	}	
}


