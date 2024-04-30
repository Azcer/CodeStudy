import java.util.Scanner;

public class helloworld {
    public static void main(String[] args) {
        try (Scanner in = new Scanner(System.in)) {
            int a = 1;
            int c = in.nextInt();
            System.out.println("Hello World\n" + "你好世界");
            System.out.println("a+b=" + (a + c) + "\n");
            System.out.println(a == c);
            System.out.println(a != c);
            System.out.println(a > c && a < c);
        }

    }
}
