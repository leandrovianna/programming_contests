//URI Online Judge - Sort Simples - 1042
package main

import "fmt"
import "sort"

func main() {
	const N int = 3
	var arr, bkp [N]int

	for i := 0; i < N; i++ {
		fmt.Scan(&arr[i])
		bkp[i] = arr[i]
	}

	sort.Ints(arr[:])

	for i := 0; i < N; i++ {
		fmt.Println(arr[i])
	}
	fmt.Println()
	for i := 0; i < N; i++ {
		fmt.Println(bkp[i])
	}
}
