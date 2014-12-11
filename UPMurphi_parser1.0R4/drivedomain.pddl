(define (domain drivedomain)
(:requirements :fluents :continuous-effects :negative-preconditions :duration-inequalities :time :typing)
(:types vehicle location)
(:predicates (at ?v - vehicle ?l - location))
(:functions (maxspeed ?v - vehicle) (speed ?v - vehicle) (traveltime ?v - vehicle) (distance ?p ?l - location))

(:durative-action accelerate
:parameters (?v - vehicle)
:duration (<= ?duration (- (maxspeed ?v) (speed ?v)))
:condition(and)
:effect (at end (increase (speed ?v) ?duration))
)

(:action drive
:parameters (?v - vehicle ?p ?l - location)
:precondition (and (at ?v ?p) (> (speed ?v) 0))
:effect (and (at ?v ?l) (not (at ?v ?p))
(increase (traveltime ?v) (/ (distance ?p ?l) (speed ?v))))
)
)

(define (problem drive-problem)
(:domain drivedomain)
(:objects  
	car - vehicle
	start - location
	tend - location
)
(:init 

	(at car start)
	(= (speed car) 0)
	(= (maxspeed car) 10)
	(= (traveltime car) 0)
	(= (distance start tend) 100)
)
(:goal (and (at car tend) (>= (traveltime car) 20)))
(:metric minimize (total-time))) 
