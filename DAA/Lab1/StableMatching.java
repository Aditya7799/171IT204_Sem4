import java.io.*;
import java.util.*;










public class StableMatching{


	public static void main(String args[])throws Exception
	{
		//read file data
		File src=new File("input.txt");
		FileInputStream i =new FileInputStream(src);
		BufferedReader b= new BufferedReader(new InputStreamReader(i));

		//assign men numbers 0-(n-1)
		String temp=b.readLine();
		String[] men_numbers = temp.split("\\s+");
		//assign women numbers 0-(n-1)
		temp=b.readLine();
		String[] women_numbers = temp.split("\\s+");
		int n = women_numbers.length;

		//reading men_preferences
		int men_preferences[][]=new int[n][n];
		for(int t=0;t<n;t++)
		{
			temp=b.readLine();
			men_preferences[t]=getPreferences(women_numbers,temp);
		}

		//reading women_preferences
		int women_preferences[][]=new int[n][n];
		for(int t=0;t<n;t++)
		{
			temp=b.readLine();
			women_preferences[t]=getPreferences(men_numbers,temp);
		}



		getStableMatching(men_preferences,women_preferences);
			


	}


	static int[] getPreferences(String numbers[],String preference)//numbers[] can be men or women	
	{	
		int array[]=new int[numbers.length];
		String temp[]=preference.split("\\s+");

		for(int i =1;i<=numbers.length;i++)
		{	

			for(int j=0;j<numbers.length;j++)
			{
				if(numbers[j].equals(temp[i]))
				{
					array[i-1]=j;
					break;
				}

			}
			

		}

		return array;




	}


	static void getStableMatching(int men_preferences[][],int women_preferences[][]){
		int n =men_preferences.length;
		int engaged[][]=new int[n][2];
		//initally all men are free
		ArrayList<Integer> freemen =new ArrayList<Integer>();
		ArrayList<Integer> freewomen=new ArrayList<Integer>();
		
		//no of ladies proposed to
		int count[]=new int[n];
		for(int i =0;i<n;i++)
			{
				engaged[i][0]=-1;
				engaged[i][1]=-1;
				freemen.add(i);
				freewomen.add(i);
			 	count[i]=0;
			}

		while(!freemen.isEmpty())
		{
			int man=freemen.remove(0);
			//sda
			int women=count[man];
			count[man]++;

			if(freewomen.contains(women))
			{
				setEngaged(man,woman,engaged);
				ArrayList.remove
			}
			else if(morePreffered(women,man,engaged))
			{
				breakUp(woman,engaged);
				setEngaged(man,woman,engaged);
			}



		}




	}



	static void setEngaged(int man,int woman,int [] engaged)
	{

	}

}