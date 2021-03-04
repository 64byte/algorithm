/*
https://www.acmicpc.net/problem/1271

Java에겐 쉬운 문제

*/

import java.math.BigInteger;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        BigInteger a, b;

        a = sc.nextBigInteger();
        b = sc.nextBigInteger();

        System.out.println(a.divide(b));
        System.out.println(a.remainder(b));
    }
}
