import java.util.*


fun main(args: Array<String>) {

    var sc: Scanner = Scanner(System.`in`)

    var hour: Int = sc.nextInt()
    var minute: Int = sc.nextInt()
    var ctime: Int = sc.nextInt()

    var total: Int = (hour * 60) + minute + ctime

    total %= (60 * 24)

    println("${total / 60} ${total % 60}")

}
