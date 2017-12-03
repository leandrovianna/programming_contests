package main

import "fmt"

func main() {
	var code, qtd int
	fmt.Scan(&code, &qtd)

	table := map[int]float64{
		1: 4.0,
		2: 4.5,
		3: 5.0,
		4: 2.0,
		5: 1.5,
	}

	var ans float64 = table[code] * float64(qtd)
	fmt.Printf("Total: R$ %.2f\n", ans)
}
