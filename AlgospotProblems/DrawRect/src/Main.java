import java.util.Scanner;
public class Main {
	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		
		Rect nRect = new Rect();
		nRect.x = new int[4];
		nRect.y = new int[4];
		
		for(int i=0; i<3; i++)
		{
			nRect.x[i] = sc.nextInt();
			nRect.y[i] = sc.nextInt();			
		}
		
		nRect = setCalc(nRect);
		
		System.out.println(nRect.x[3] + " " + nRect.y[3]);
	}
	
	static Rect setCalc(Rect nRect)
	{
		nRect.x[3] = nRect.x[1] - nRect.x[0] + nRect.x[2];
		nRect.y[3] = nRect.y[1] - nRect.y[0] + nRect.y[2];
		
		return nRect;
	}
}

class Rect {
	
	int x[];
	int y[];
}
