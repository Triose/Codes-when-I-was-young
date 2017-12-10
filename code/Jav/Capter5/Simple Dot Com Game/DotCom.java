
public class DotCom {
    private final int maxLength = 10;
    private int startPoint;
    private int length;
    private boolean [] isHacked;
    public DotCom(int chessBoardLength) {
	startPoint = (int)(Math.random() * chessBoardLength);
	length = (int)(Math.random() * maxLength);
	while(length == 0 || startPoint + length - 1 > chessBoardLength) {
	    length = (int)(Math.random() * 10);
	}
	isHacked = new boolean [length];
	for(int i = 0; i < isHacked.length; i++) {
	    isHacked[i] = false;
	}
    }
    public boolean checkHacked(int hackedPoint) {
	hackedPoint -= startPoint;
	if(hackedPoint < length && hackedPoint >= 0 && !isHacked[hackedPoint]) {
	    return true;
	}
	return false;
    }
    public void markHackedPoint(int hackedPoint) {
	hackedPoint -= startPoint;
	isHacked[hackedPoint] = true;
    }
    public boolean exist() {
	for(int i = 0; i < isHacked.length; i++) {
	    if(!isHacked[i]) return true;
	}
	return false;
    }
    public int getStartPoint() {
	return startPoint;
    }
    public int getLength() {
	return length;
    }
}
