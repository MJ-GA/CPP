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

System.out.println("Enter the number of samples to generate: ");

n = input.nextInt();

if (n > 0) {

int[] myArray = createArray(n);

printResults(obj.calculateMean(myArray), obj.calculateSTDDev(myArray));

System.out.println("Enter choice : "
		+ "\n1.Re enter number of samples to generate "
		+ "\n2.exit ");
choice =input.nextInt();

} else {
	System.out.println("Please enter a number that is greater than zero");
	System.out.flush();

	}
} while (choice < 2); }


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
