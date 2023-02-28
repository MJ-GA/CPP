import java.util.Random;
import java.util.Scanner;
public class Week8 {

static {

System.loadLibrary("Lab8"); 

	}

public native double calculateSTDDev(int[] numbers);

public native double calculateMean(int[] numbers);


public static void main(String[] args) {

Week8 obj = new Week8(); 

Scanner input = new Scanner(System.in);

int choice = 0 ;


int n ;

do {

System.out.println("Enter choice : "
		+ "\n1.Re enter number of samples to generate "
		+ "\n2.Check time after and time before "
		+ "\n3.exit ");
	 long result;
choice =input.nextInt();

if (choice==1) {
System.out.println("Enter the number of samples to generate: ");
n = input.nextInt();
	int[] myArray = createArray(n);
	


long timeBefore = System.currentTimeMillis();
printResults(obj.calculateMean(myArray), obj.calculateSTDDev(myArray));
long timeAfter = System.currentTimeMillis();
 result = timeAfter-timeBefore ;
 System.out.println("The difference in time before and after the calculation is : "+result+" milliseconds");}

else if (choice==2) {
System.out.println("Time Before in milli : ");

}


} while (choice < 3); }


private static void printResults(double mean, double std) {

System.out.println("Mean = "+mean);

System.out.println("Standard Deviation = "+std); 

}

private static int[] createArray(int n) {

Random random = new Random();

int[] myArray = new int[n];

for (int i = 0; i < n; i++) {

myArray[i] = random.nextInt(100);

}

return myArray;

}
} 
