/*
https://leetcode.com/problems/two-sum/

scala 공부용.

*/

import scala.collection.mutable

object Solution {
  def twoSum(nums: Array[Int], target: Int): Array[Int] = {
    var map = mutable.HashMap[Int, Int]()

    for (i <- nums.indices) {
      var diff = target - nums(i)

      if (map.contains(diff)) {
        return Array(map(diff), i)
      } else {
        map.put(nums(i), i)}
    }

    map.toArray.map(_._2)
  }
}
