package main

import "fmt"

func main() {
	const N = 5
	var x int
	count := map[string]int{
		"par(es)":     0,
		"impar(es)":   0,
		"positivo(s)": 0,
		"negativo(s)": 0,
	}

	for i := 0; i < N; i++ {
		fmt.Scan(&x)

		if x&1 == 1 {
			count["impar(es)"]++
		} else {
			count["par(es)"]++
		}

		if x > 0 {
			count["positivo(s)"]++
		} else if x < 0 {
			count["negativo(s)"]++
		}
	}

	keys := []string{
		"par(es)",
		"impar(es)",
		"positivo(s)",
		"negativo(s)",
	}

	for _, v := range keys {
		fmt.Printf("%d valor(es) %s\n", count[v], v)
	}
}
