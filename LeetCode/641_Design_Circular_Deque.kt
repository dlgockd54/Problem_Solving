import java.util.LinkedList

/*
641. Design Circular Deque

Design your implementation of the circular double-ended queue (deque).

Your implementation should support following operations:

MyCircularDeque(k): Constructor, set the size of the deque to be k.
insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
getRear(): Gets the last item from Deque. If the deque is empty, return -1.
isEmpty(): Checks whether Deque is empty or not.
isFull(): Checks whether Deque is full or not.

Example:

MyCircularDeque circularDeque = new MyCircularDeque(3); // set the size to be 3
circularDeque.insertLast(1);			// return true
circularDeque.insertLast(2);			// return true
circularDeque.insertFront(3);			// return true
circularDeque.insertFront(4);			// return false, the queue is full
circularDeque.getRear();  			// return 2
circularDeque.isFull();				// return true
circularDeque.deleteLast();			// return true
circularDeque.insertFront(4);			// return true
circularDeque.getFront();			// return 4


Note:

All values will be in the range of [0, 1000].
The number of operations will be in the range of [1, 1000].
Please do not use the built-in Deque library.
*/

class MyCircularDeque(private val k: Int) {

    /** Initialize your data structure here. Set the size of the deque to be k. */
    private val mInnerList = LinkedList<Int>()

    private fun isAddable() = mInnerList.size < k

    private fun isRemovable() = mInnerList.size > 0

    /** Adds an item at the front of Deque. Return true if the operation is successful. */
    fun insertFront(value: Int): Boolean {
        return if (isAddable()) {
            mInnerList.add(0, value)

            true
        } else {
            false
        }
    }

    /** Adds an item at the rear of Deque. Return true if the operation is successful. */
    fun insertLast(value: Int): Boolean {
        return if (isAddable()) {
            mInnerList.add(value)

            true
        } else {
            false
        }
    }

    /** Deletes an item from the front of Deque. Return true if the operation is successful. */
    fun deleteFront(): Boolean {
        return if (isRemovable()) {
            mInnerList.remove()

            true
        } else {
            false
        }
    }

    /** Deletes an item from the rear of Deque. Return true if the operation is successful. */
    fun deleteLast(): Boolean {
        return if (isRemovable()) {
            mInnerList.removeAt(mInnerList.size - 1)

            true
        } else {
            false
        }
    }

    /** Get the front item from the deque. */
    fun getFront(): Int {
        return if (isRemovable()) {
            mInnerList[0]
        } else {
            -1
        }
    }

    /** Get the last item from the deque. */
    fun getRear(): Int {
        return if (isRemovable()) {
            mInnerList[mInnerList.size - 1]
        } else {
            -1
        }
    }

    /** Checks whether the circular deque is empty or not. */
    fun isEmpty(): Boolean {
        return isRemovable().not()
    }

    /** Checks whether the circular deque is full or not. */
    fun isFull(): Boolean {
        return isAddable().not()
    }
}
