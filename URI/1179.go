package main

import "fmt"

func main() {
	const N = 15, T = 5
	v1, v2 int[T]
	var x, s1, s2 int

	s1 = 0
	s2 = 0
	for i := 0; i < N; i++ {
		fmt.Scan(&x)
		if x % 2 == 0 {
				v1[s1] = x
				s1++
				if s1 == 5 {
					for j, v range v1 {
						fmt.Printf("par[%d] = %d\n", j, v)
					}
					s1 = 0
				}
		} else {
				v2[s2] = x
				s2++
				if s2 == 5 {
					for j, v range v2 {
						fmt.Printf("impar[%d] = %d\n", j, v)
					}
					s2 = 0
				}
		}
	}
