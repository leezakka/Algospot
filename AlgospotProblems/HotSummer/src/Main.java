import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

		Scanner sc = new Scanner(System.in);
		// set Building count
		int nBuildingCount = sc.nextInt();
		int[] nVolt = new int[9];
		
		Building[] bd = new Building[nBuildingCount];
		
		// Initialize
		for(int i=0; i<bd.length; i++)
		{
			bd[i] = new Building();
		}
		
		for(int i=0; i<nBuildingCount; i++)
		{
			// set TargetVolt
			int setTargetVolt = sc.nextInt();
			bd[i].setTargetVolt(setTargetVolt);
			
			// set volt;
			nVolt[0] = sc.nextInt();
			nVolt[1] = sc.nextInt();
			nVolt[2] = sc.nextInt();
			nVolt[3] = sc.nextInt();
			nVolt[4] = sc.nextInt();
			nVolt[5] = sc.nextInt();
			nVolt[6] = sc.nextInt();
			nVolt[7] = sc.nextInt();
			nVolt[8] = sc.nextInt();
			bd[i].setVolt(nVolt);
		}
		
		// print
		for(int i=0; i<nBuildingCount; i++)
		{
			bd[i].isTrueVolt();
		}
		sc.close();
	}
}

class Building
{
	int nCount;
	int nTargetVolt;
	int nVolt[];
	int total;
	
	Building()
	{
		this.nCount = 0;
		this.nTargetVolt = 0;
		this.total = 0;
		this.nVolt = new int[9];
	}
	
	int setTargetVolt(int v)
	{
		return this.nTargetVolt = v;
	}
	
	void setVolt(int v[])
	{
		System.arraycopy(v, 0, this.nVolt, 0, 9);
	}
	
	void isTrueVolt()
	{
		this.calcVolt();
		
		if(this.nTargetVolt >= this.total)
		{
			System.out.print("YES\n");
		}
		else
		{
			System.out.print("NO\n");
		}
	}
	
	void calcVolt()
	{
		for(int i=0; i<9;i++)
		{
			this.total += this.nVolt[i];
		}
	}
	
	void printVolt()
	{
		System.out.println(this.nTargetVolt);
	}
}
