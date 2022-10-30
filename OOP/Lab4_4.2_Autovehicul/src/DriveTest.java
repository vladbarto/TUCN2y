public class DriveTest {
    public static void main(String[] args) throws Exception {
        Helm driver = new Helm();
        Autovehicul car = new Autovehicul("Vauxhall", "silver", 100, 5, 185);
        //car.accelerate(35);
        //car.decelerate(50);
        //car.changeGear(3);
        System.out.println(car.getCurrentGear());
        System.out.println(car.toString());
    }
}