namespace Starplayer39.FractionFS

open System

module Fraction =

    let rec Gcd x y  =
        let x' = max x y
        let y' = min x y

        let z = x' % y'

        match z with
        | 0 -> Math.Abs y'
        |_ -> Gcd y' z

    let Lcm x y = Math.Abs ((x * y) / Gcd x y)
