import java.math.BigInteger;

public class MainClass {
	public static void main(String[] args)
	{
		int i; // puterea i
		
		BigInteger sum = new BigInteger("1");
		for(i = 1; i <= 64; i++)
		{
			System.out.println(i+". Suma boabelor de orez de pe toata tabla este " + sum);
			sum =  sum.multiply(new BigInteger("2"));
			
		}
		System.out.println("Suma boabelor de orez de pe toata tabla este " + sum.divide(new BigInteger("2")));
		
		//sau varianta 2: calculam exponentul i
		BigInteger doi = new BigInteger("2");
		i = 64;
		int exponent = i-1;
		sum = new BigInteger("0");
		sum = sum.add(doi.pow(exponent));
		System.out.println("In varianta 2, reiese ca suma este "+ sum);
	}
}
