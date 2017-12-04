package main

import (
	"fmt"
	"sort"
)

func abs(x int) int {
	if x < 0 {
		x *= -1
	}
	return x
}

func max(x, y int) int {
	if x > y {
		return x
	} else {
		return y
	}
}

func main() {
	const N = 110
	var t, n int
	var arr [N]int
	var bkp [N]int

	fmt.Scan(&t)
	for ti := 0; ti < t; ti++ {
		fmt.Scan(&n)
		for i := 0; i < n; i++ {
			fmt.Scan(&arr[i])
		}
		for i := n; i < N; i++ {
			arr[i] = 1000000
		}

		sort.Ints(arr[:])

		answer := 0

		for i := 0; i < 2; i++ {
			var k, l = n - 1, 0
			var fl = i == 0
			var p1, p2 int

			p1 = n / 2
			p2 = n / 2

			for p1 >= 0 {
				if p1 == p2 {
					if fl {
						bkp[p1] = arr[k]
						k--
					} else {
						bkp[p1] = arr[l]
						l++
					}
				} else {
					if fl {
						bkp[p1] = arr[k]
						k--
						bkp[p2] = arr[k]
						k--
					} else {
						bkp[p1] = arr[l]
						l++
						bkp[p2] = arr[l]
						l++
					}
				}

				fl = !fl
				p1--
				p2++
			}

			var local_ans = 0
			for j := 1; j < n; j++ {
				local_ans += abs(bkp[j] - bkp[j-1])
			}

			answer = max(answer, local_ans)
		}

		fmt.Printf("Case %d: %d\n", ti+1, answer)
	}

}
