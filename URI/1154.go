package main

import "fmt"

func main() {
	var x, sum, qtd int

	sum = 0
	qtd = 0

	for fmt.Scan(&x); x >= 0; {
		sum += x
		qtd++
		fmt.Scan(&x)
	}

	var answer float64 = float64(sum) / float64(qtd)
	fmt.Printf("%.2f\n", answer)
}
