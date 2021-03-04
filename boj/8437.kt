import java.math.BigInteger
import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)

    var a = sc.nextBigInteger()
    var b = sc.nextBigInteger()
    var div = BigInteger.valueOf(2)

    println(a.add(b).divide(div))
    println(a.subtract(b).divide(div))
}
