import java.util.Scanner;
import java.util.Stack;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Stack<Character> st = new Stack<Character>();
		Scanner sc = new Scanner(System.in);		
		
		int T = 0;
		// Get Program Count
		T = sc.nextInt();

		// Run T
		for(int count = 0; count < T; count++)
		{
			// Input Bracket
			String sInput = sc.next();
			
			// Push First Element
			st.push(sInput.charAt(0));
			char stTop = (char) st.peek();

			// Compare from Second Element
			for(int i=1; i< sInput.length(); i++)
			{				
					if( (stTop =='(' && sInput.charAt(i) == ')') || (stTop =='{' && sInput.charAt(i) == '}') || (stTop =='[' && sInput.charAt(i) == ']'))
					{
						st.pop();
						if(!st.isEmpty())
							stTop = (char) st.peek();
					}
					else
					{							
						st.push(sInput.charAt(i));		
						stTop = (char) st.peek();
					}
			}
			
			// Print Result
			if(st.isEmpty())
			{
				System.out.println("YES");
				st.clear();
			}
			else
			{
				System.out.println("NO");
				// Clear Stack
				st.clear();
			}
		}
		// Close Scanner
		sc.close();
	}	
}
