import java.util.Scanner;


public class Game {
    private DotCom dotcom = null;
    private int tryTimes = 0;
    private int chessBoardLength = 0;
    private final int chessBoardMaxLength = 50;
    public Game() {
	chessBoardLength = (int)(Math.random() * chessBoardMaxLength);
	while(chessBoardLength == 0) {
	    chessBoardLength = (int)(Math.random() * chessBoardMaxLength);
	}
	dotcom = new DotCom(chessBoardLength);
	tryTimes = 0;
    }
    private boolean valid(int hackedPoint) {
	if(hackedPoint < 1 || hackedPoint > chessBoardLength) return false;
	return true;
    }
    public void Run() {
	System.out.println("This game has 1 chessboard with length equals " + chessBoardLength + " and 1 DotCom.");
	int hackedPoint;
	Scanner reader = new Scanner(System.in);
	do {
	    System.out.println("Please input the position you want to hack.");
	    hackedPoint = reader.nextInt();
	    tryTimes++;
	    if(!valid(hackedPoint)) {
		System.out.println("The position you input is not valid. Please input again.");
		continue;
	    }
	    if(dotcom.checkHacked(hackedPoint)) {
		dotcom.markHackedPoint(hackedPoint);
		System.out.println("Success!");
	    } else {
		System.out.println("Failed!");
	    }
	} while(dotcom.exist());
    }
    public void Over() {
	System.out.println("Congratulation! You Win with " + tryTimes + " times tried");
	System.out.println("The DotCom located between " + dotcom.getStartPoint() + " and " + (dotcom.getStartPoint() + dotcom.getLength() - 1));
    }
}

