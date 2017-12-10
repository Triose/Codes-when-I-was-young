
public class valueTransmitJava {

    int age;

    public static void main(String [] argv) {
	valueTransmitJava s = new valueTransmitJava();
	s.age = 100;
	changeAge(s);
	System.out.println("Age is: " + s.age);
    }

    public static void changeAge(valueTransmitJava s) {
	s.age++;
    }
}
