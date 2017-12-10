public class TypeTransformTestDrive {
    public static long calcArea(int height, int width) {
	return (long)height * width;
    }

    public static void main(String [] args) {
	byte h = 7; int w = 7;
	int res = (int)calcArea(h, w);
	System.out.println(res);
    }
}
