import java.util.Scanner

fun main(args: Array<String>) {
    val sc: Scanner = Scanner(System.`in`)

    var value: Int = 0
    var sum: Int = 0
    for (_1 in 1..5) {
        value = sc.nextInt()
        sum += value
    }

    println(sum)
}
