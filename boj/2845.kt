/*
https://www.acmicpc.net/problem/2845

코틀린으로 기초 문제를 풀어보자.

*/

import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)

    var a: Int = sc.nextInt()
    var b: Int = sc.nextInt()

    var total = a*b


    var c: Int = 0
    for (i in 1..5) {
        c = sc.nextInt()
        print((c-total).toString() + " ")
    }
}
