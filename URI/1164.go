package main

import "fmt"

func main() {
	var n, t int
	var divs []int

	for fmt.Scan(&t); t > 0; t-- {
		divs = divs[:0] // limpando o slice

		fmt.Scan(&n)

		for i := 1; i*i <= n; i++ {
			if n%i == 0 {
				divs = append(divs, i)
				divs = append(divs, n/i)
			}
		}

		sum := 0
		for _, v := range divs {
			sum += v
		}
		sum -= n

		if n != 1 && sum == n {
			fmt.Printf("%d eh perfeito\n", n)
		} else {
			fmt.Printf("%d nao eh perfeito\n", n)
		}
	}
}
