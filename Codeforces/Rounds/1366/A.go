// Codeforces - Shovels and Swords - 1366A
package main

import "fmt"

func Min(x, y int) int {
	if x < y {
		return x
	} else {
		return y
	}
}

func main() {
	var t, a, b int
	fmt.Scan(&t)
	for i := 0; i < t; i++ {
		fmt.Scan(&a, &b)
		fmt.Println(Min(a, Min(b, (a+b)/3)))
	}
}
