public class GuessGame {
    private Player p1 = null;
    private Player p2 = null;
    private Player p3 = null;

    GuessGame() {}
    public void startGame() {
	p1 = new Player();
	p2 = new Player();
	p3 = new Player();

	int guessp1 = 0;
	boolean p1isRight = false;
	int guessp2 = 0;
	boolean p2isRight = false;
	int guessp3 = 0;
	boolean p3isRight = false;

	int targetNumber = (int)(Math.random() * 10);
	System.out.println("Im thinking of a number between 0 and 9...");

	while(true) {
	    System.out.println("Number to guess is " + targetNumber);

	    guessp1 = p1.guess();
	    guessp2 = p2.guess();
	    guessp3 = p3.guess();

	    if(guessp1 == targetNumber) p1isRight = true;
	    if(guessp2 == targetNumber) p2isRight = true;
	    if(guessp3 == targetNumber) p3isRight = true;

	    if(p1isRight || p2isRight || p3isRight) {
		System.out.println("We have a winner!");
		System.out.println("Player one got it right? " + p1isRight);
		System.out.println("Player two got it right? " + p2isRight);
		System.out.println("Player three got it right? " + p3isRight);
		break;
	    } else {
		System.out.println("Players will have to try again.\n");
	    }
	}
    }
}
