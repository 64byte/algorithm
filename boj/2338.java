/*
https://www.acmicpc.net/problem/2338

BigInteger를 쓰면 쉬운 문제.

C++는 구현되어 있지 않으니 귀찮은 문제.

*/

import java.math.BigInteger;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a, b;

        a = sc.nextBigInteger();
        b = sc.nextBigInteger();

        System.out.println(a.add(b));
        System.out.println(a.subtract(b));
        System.out.println(a.multiply(b));
    }
}
