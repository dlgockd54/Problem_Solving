import java.util.*

class Solution {

    private lateinit var mSequence: ArrayList<Int>
    private var n = 0
    private var s = 0
    private var mAnswer = 0

    fun solution(sequence: ArrayList<Int>, n: Int, s: Int) {
        mSequence = sequence
        this.n = n
        this.s = s

        mSequence.forEachIndexed { index, value ->
            findAnswer(sequence.subList(index, index + 1), index)
        }

        println(mAnswer)
    }

    private fun findAnswer(partialSequence: MutableList<Int>, idx: Int) {
        if (partialSequence.sum() == s) {
            mAnswer++
        }

        for (i in idx + 1 until mSequence.size) {
            val newList = ArrayList<Int>(partialSequence)
                    .apply {
                        add(mSequence[i])
                    }

            findAnswer(newList, i)
        }
    }
}

fun main() {
    val sc = Scanner(System.`in`)
    val n = sc.nextInt()
    val s = sc.nextInt()
    val sequence = arrayListOf<Int>()

    for (i in 0 until n) {
        sequence.add(sc.nextInt())
    }

    Solution().solution(sequence, n, s)
}
