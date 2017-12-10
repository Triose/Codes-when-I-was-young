public class Player {
    public int guess() {
	int num = (int)(Math.random() * 10);
	System.out.println("I'm guessing " + num);
	return num;
    }
}
