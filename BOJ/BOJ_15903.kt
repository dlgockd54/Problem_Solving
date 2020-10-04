import java.util.*

class Solution {

    fun solution() {
        val sc = Scanner(System.`in`)
        val pq = PriorityQueue<Long>()
        val n = sc.nextInt()
        val m = sc.nextInt()
        var answer = 0L

        for (i in 0 until n) {
            pq.add(sc.nextLong())
        }

        for (i in 0 until m) {
            val first = pq.remove()
            val second = pq.remove()
            val sum = first + second

            pq.add(sum)
            pq.add(sum)
        }

        answer = pq.sum()

        println(answer)
    }
}

fun main() {

    Solution().solution()
}