package main

import "fmt"

func main() {
	var n1, n2 float64

begin:
	n1 = 11
	n2 = 11

	for fmt.Scan(&n1); n1 < 0 || n1 > 10; {
		fmt.Println("nota invalida")
		fmt.Scan(&n1)
	}

	for fmt.Scan(&n2); n2 < 0 || n2 > 10; {
		fmt.Println("nota invalida")
		fmt.Scan(&n2)
	}

	mean := float64(n1+n2) / 2.0

	fmt.Printf("media = %.2f\n", mean)

	var cod int

	fmt.Println("novo calculo (1-sim 2-nao)")
	for fmt.Scan(&cod); cod != 1 && cod != 2; {
		fmt.Println("novo calculo (1-sim 2-nao)")
		fmt.Scan(&cod)
	}

	if cod == 1 {
		goto begin
	}
}
