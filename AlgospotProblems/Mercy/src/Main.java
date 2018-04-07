import java.util.Scanner;

public class Main {

	public static int main(String[] args) {
		// TODO Auto-generated method stub

	Scanner sc = new Scanner(System.in);
		
		// Input
		System.out.println("Input Num of count : ");
		int nCount = sc.nextInt();
		
		// Error
		try{
			if(nCount>10)
			{
				throw new Exception("overflow");
			}
		}
		catch (Exception e)
		{
			String str = e.getMessage();
			System.err.println(str);
			System.exit(0);
		}
		
		while(nCount>0)
		{
			System.out.print("Hello Algospot!\n");
			nCount--;
		}
	
		sc.close();
		return 0;
	}
}