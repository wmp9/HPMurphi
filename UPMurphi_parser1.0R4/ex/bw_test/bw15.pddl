(define (problem BW-rand-15)
(:domain blocksworld)
(:objects b1 b2 b3 b4 b5 b6 b7 b8 b9 b10 b11 b12 b13 b14 b15  - block)
(:init
(handempty)
(on b1 b6)
(ontable b2)
(on b3 b12)
(on b4 b11)
(on b5 b2)
(ontable b6)
(on b7 b14)
(on b8 b10)
(on b9 b15)
(ontable b10)
(on b11 b9)
(on b12 b13)
(on b13 b7)
(on b14 b8)
(on b15 b3)
(clear b1)
(clear b4)
(clear b5)
)
(:goal
(and
(on b1 b5)
(on b3 b12)
(on b4 b13)
(on b5 b2)
(on b6 b8)
(on b7 b9)
(on b8 b15)
(on b9 b1)
(on b10 b6)
(on b12 b11)
(on b13 b10)
(on b14 b4)
(on b15 b3))
)
)
