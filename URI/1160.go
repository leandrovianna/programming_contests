package main

import "fmt"

func main() {
	var n int
	var pa, pb int
	var g1, g2 float64

	for fmt.Scan(&n); n > 0; n-- {
		fmt.Scan(&pa, &pb, &g1, &g2)

		g1 /= 100
		g2 /= 100

		var i int
		for i = 0; i <= 100 && pa <= pb; i++ {
			pa += int(float64(pa) * g1)
			pb += int(float64(pb) * g2)
		}

		if i > 100 {
			fmt.Println("Mais de 1 seculo.")
		} else {
			fmt.Printf("%d anos.\n", i)
		}
	}
}
