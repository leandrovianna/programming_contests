package main

import "fmt"

func main() {
	var value float64
	fmt.Scanf("%f", &value)

	var m float64 = value
	m += 0.001

	var notas []float64 = []float64{100, 50, 20, 10, 5, 2, 1,
		0.5, 0.25, 0.10, 0.05, 0.01}

	var notas_qtd map[float64]int = map[float64]int{100: 0, 50: 0, 20: 0, 10: 0,
		5: 0, 2: 0, 1: 0, 0.50: 0, 0.25: 0, 0.10: 0, 0.05: 0, 0.01: 0}

	for _, d := range notas {
		for m-d >= 0 {
			notas_qtd[d]++
			m -= d
		}
	}

	var str string = "nota"
	fmt.Println("NOTAS:")
	for _, d := range notas {
		c := notas_qtd[d]
		if d == 1.0 {
			fmt.Println("MOEDAS:")
			str = "moeda"
		}
		fmt.Printf("%d %s(s) de R$ %.2f\n", c, str, d)
	}
}
