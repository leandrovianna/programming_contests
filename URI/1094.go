package main

import "fmt"

func percentage(fraction, total int) float64 {
	return float64(fraction) / float64(total) * 100.0
}

func main() {
	var n int
	fmt.Scan(&n)

	var total = 0
	exp := map[string]int{
		"C": 0,
		"R": 0,
		"S": 0,
	}

	for i := 0; i < n; i++ {
		var q int
		var c string

		fmt.Scan(&q, &c)
		exp[c] += q
		total += q
	}

	fmt.Printf("Total: %d cobaias\n", total)
	fmt.Printf("Total de coelhos: %d\n", exp["C"])
	fmt.Printf("Total de ratos: %d\n", exp["R"])
	fmt.Printf("Total de sapos: %d\n", exp["S"])
	fmt.Printf("Percentual de coelhos: %.2f %%\n", percentage(exp["C"], total))
	fmt.Printf("Percentual de ratos: %.2f %%\n", percentage(exp["R"], total))
	fmt.Printf("Percentual de sapos: %.2f %%\n", percentage(exp["S"], total))
}
