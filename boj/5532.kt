/*
https://www.acmicpc.net/problem/5532
*/

import java.util.*
import kotlin.math.max


fun main(args: Array<String>) {

    val sc: Scanner = Scanner(System.`in`)

    var l: Int = sc.nextInt()
    var a: Int = sc.nextInt()
    var b: Int = sc.nextInt()
    var c: Int = sc.nextInt()
    var d: Int = sc.nextInt()

    var e: Int = (b/d)
    var left: Int = e
    if ((b/d.toDouble()) != e.toDouble()) {
        left += 1
    }

    var f: Int = (a/c)
    var left2: Int = f
    if ((a/c.toDouble()) != f.toDouble()) {
        left2 += 1
    }

    println("${l - max(left, left2)}")
}
