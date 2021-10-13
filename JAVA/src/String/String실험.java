package String;

public class String실험 {

    static class Car {
        private String name;

        public Car(String name) {
            this.name = name;
        }
    }

    static class Animal {
        private String name;

        public Animal(String name) {
            this.name = name;
        }
    }

    static abstract class A {
        public void speaking() {
            System.out.println("ddd");
        }

        public abstract void sleeping();
    }

    public static void main(String[] args) {

        Car car = new Car("이름");

    }

}
