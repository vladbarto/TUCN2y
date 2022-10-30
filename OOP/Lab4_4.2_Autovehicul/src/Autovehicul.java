public class Autovehicul {
    private String marca;
    private String colour;
    private int currentSpeed;
    private int currentGear;
    private int maxSpeed;
    private static final int MAX_NO_OF_GEARS = 6;
    public Autovehicul(){
    }
    public Autovehicul(String marca, String colour, int currentSpeed, int currentGear, int maxSpeed) {
        this.marca = marca;
        this.colour = colour;
        this.currentSpeed = currentSpeed;
        this.currentGear = currentGear;
    }
    public String getMarca() {
        return marca;
    }
    public String getColour() {
        return colour;
    }
    public int getCurrentSpeed() {
        return currentSpeed;
    }
    public int getCurrentGear() {
        return currentGear;
    }
    public int getMaxSpeed() {
        return maxSpeed;
    }
    public void setMarca(String marca) {
        this.marca = marca;
    }
    public void setColour(String colour) {
        this.colour = colour;
    }
    public void setCurrentSpeed(int currentSpeed) {
        this.currentSpeed = currentSpeed;
    }
    public void setCurrentGear(int currentGear) {
        this.currentGear = currentGear;
    }
    public void setMaxSpeed(int maxSpeed) {
        this.maxSpeed = maxSpeed;
    }

    @Override
    public String toString() {
        return "Autovehicul{" +
                "marca='" + marca + '\'' +
                ", colour='" + colour + '\'' +
                ", currentSpeed=" + currentSpeed +
                ", currentGear=" + currentGear +
                ", maxSpeed=" + maxSpeed +
                '}';
    }

    ///Methods
    public void accelerate(int aditionalSpeed) {
        if(currentSpeed + aditionalSpeed > maxSpeed)
            currentSpeed = maxSpeed;
        else
            currentSpeed += aditionalSpeed;
    }
    public void decelerate(int minusSpeed)
    {
        if(currentSpeed-minusSpeed < 0)
            currentSpeed = 0;
        else
            currentSpeed -= minusSpeed;
    }
    public void comeToAHalt(){
        currentSpeed = 0;
    }
    public void changeGear(int newGear) throws Exception {
        if(newGear < 1 || newGear > MAX_NO_OF_GEARS)
            throw new Exception("bai la transmisie");
        else
            currentGear = newGear;
    }

}
