package main

import "fmt"

func main() {
	var n int

	fmt.Scan(&n)

	k := 1
	for i := 0; i < n; i++ {
		for j := 0; j < 4; j++ {
			if j == 3 {
				fmt.Printf("PUM\n")
			} else {
				fmt.Printf("%d ", k)
			}
			k++
		}
	}
}
