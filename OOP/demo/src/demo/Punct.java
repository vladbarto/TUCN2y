package demo;

public class Punct {
	private int x;
	private int y;
	private int z;
	public Punct(int x, int y, int z, int dim) {
		if(x >= -dim && x <= dim && y >= -dim && y <= dim && z >= -dim && z <= dim) {
			this.x = x;
			this.y = y;
			this.z = z;
		}
	}
	
	public int getX() {
		return x;
	}

	public void setX(int x) {
		this.x = x;
	}

	public int getY() {
		return y;
	}

	public void setY(int y) {
		this.y = y;
	}

	public int getZ() {
		return z;
	}

	public void setZ(int z) {
		this.z = z;
	}

	public double calculateEuclidianDistance(Punct p2) {
		return (double)sqrt(Math.pow(p2.getX()-x, 2), Math.pow(p2.getY()-y, 2), Math.pow(p2.getZ()-z, 2));
	}
}
