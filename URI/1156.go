package main

import "fmt"

func s() float64 {

	var f float64 = 0.0
	var i, j = 1, 1

	for i <= 39 {
		// fmt.Printf("%d/%d\n", i, j)
		f += float64(i) / float64(j)
		i += 2
		j *= 2
	}

	return f
}

func main() {
	fmt.Printf("%.2f\n", s())
}
