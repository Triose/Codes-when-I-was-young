

class Dog {
    public int age;
    void bark() {
	System.out.println("WWW");
    }
}



public class EG1 {
    public static void check(Dog dog) {
	System.out.println("I'm " + dog.age + " years old");
	dog.bark();
	dog.age = -10;
    }

    public static void test(int x) {
	System.out.println("x = " + x);
	x += 100;
    }


    public static void main(String [] args) {
	Dog dog = new Dog();
	dog.age = 10000;
	EG1.check(dog);
	System.out.println("I'm " + dog.age + " years old");
	int x = 100;
	EG1.test(x);
	System.out.println("x2 = " + x);
    }
}
//类的对象通过引用传递，而主数据类型只是值传递
