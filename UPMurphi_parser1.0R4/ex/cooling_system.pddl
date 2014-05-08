(define (domain cooling_system)
(:requirements :fluents :durative-actions :duration-inequalities :typing :negative-preconditions :time :disjunctive-preconditions )
(:types tank pump)
(:predicates (system_start) (fail) (filling ?t - tank ?p - pump) (busy ?p - pump))
(:functions (x ?t -  tank) (v ?t - tank) (c ?t - tank) (v_in ?p - pump) (r ?t - tank) (system_counter))


(:durative-action fill
 :parameters (?t - tank ?p - pump)
 :duration (>= ?duration  0)		 
 :condition (and 
	(at start (not(busy ?p)))
	(over all (>= (x ?t) (r ?t)))
	(over all (>= (x ?t) 0))
	(over all (<= (x ?t) (c ?t)))
	)
 :effect (and 
		(at start (busy ?p))
		;(at start (system_start))
		(at start (filling ?t ?p))		
		(at end (not(filling ?t ?p)))
		(at end (not(busy ?p)))
	    )
	)

(:process system_activity
 :parameters ()
 :precondition (and (system_start) )
 :effect (and 
		(increase (system_counter) (* #t 1))
	    )
	)


(:event failure
 :parameters (?t - tank)
 :precondition (or 
	(< (x ?t) (r ?t)) 
	(> (x ?t) (c ?t)) 
	(> (system_counter) 10)
	)
 :effect (and 
		(fail)
	    )
)

(:event failure2
 :parameters (?p1 ?p2 - pump)
 :precondition (and (system_start)
	(not (busy ?p1))
	(not (busy ?p2))
	)
 :effect (and 
		(fail)
	    )
)

(:process fill_tank
 :parameters (?t - tank ?p - pump)
 :precondition (and (filling ?t ?p) (system_start))
 :effect (and 
		(increase (x ?t) (* #t (v_in ?p) )  )
	    )
)

(:process leak_tank
 :parameters (?t - tank)
 :precondition (and (system_start))
 :effect (and 
		(decrease (x ?t) (* #t  (v ?t)  )  )
	    )
)


)

(define (problem cooling_system_1)
    (:domain cooling_system)
    (:objects tank1 tank2 tank3 - tank pump1 pump2 - pump)
    (:init 	
	(= (x tank1) 0.2)	
	(= (x tank2) 0.6)	
	(= (x tank3) 0.9)

	(= (c tank1) 1.5)	
	(= (c tank2) 1.5)	
	(= (c tank3) 1.5)

	(= (r tank1) 0.1)	
	(= (r tank2) 0.2)	
	(= (r tank3) 0.2)	

	(= (v tank1) 0.1)	
	(= (v tank2) 0.3)	
	(= (v tank3) 0.2)	

	(= (v_in pump1) 0.4)	
	(= (v_in pump2) 0.2)	
	(= (system_counter) 0)
	(system_start)
	(not(fail))
     )  
     (:goal (and  (not(fail)) (= (system_counter) 10)) )
     (:metric minimize (total-time))) 


