namespace Utility

module Utility =
    let Gcd (x' : int, y' : int) : int =
        let mutable tmp : int = 0
        let mutable n : int = 0
        let mutable x : int = x';
        let mutable y : int = y';

        if x < y then
            tmp <- x
            x <- y
            y <- tmp

        while y <> 0 do
            n <- x % y
            x <- y
            y <- n

        System.Math.Abs(x)

    let Lcm (x : int, y : int) : int =
        System.Math.Abs((x * y) / Gcd(x, y));
