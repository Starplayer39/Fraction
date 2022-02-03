package starplayer39.faction.kotlin.utility

import kotlin.math.abs

class Utility {
    companion object {

        public fun gcd(x: Int, y: Int): Int {

            var a: Int = x
            var b: Int = y
            var n: Int = 0

            if (x < y) {
                a = y
                b = x
            }

            while (b != 0) {
                n = a % b
                a = b
                b = n
            }

            return abs(a)
        }

        public fun lcm(x: Int, y: Int): Int {
            return abs((x * y) / gcd(x, y))
        }
    }
}