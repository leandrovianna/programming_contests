package main

import "fmt"

func main() {
	var x, z int

	fmt.Scan(&x)

	for fmt.Scan(&z); z <= x; {
		fmt.Scan(&z)
	}

	answer := 0
	sum := 0
	for i := x; sum <= z; i++ {
		sum += i
		answer++
	}

	fmt.Println(answer)
}
