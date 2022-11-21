package demo;

public class Shape {
	private static int counter;
	
	public Shape() {
		counter++;
	}
	
	public static int getCounter() {
		return counter;
	}

	public static void setCounter(int counter) {
		Shape.counter = counter;
	}
	
}
