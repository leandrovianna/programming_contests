package main

import (
	"bufio"
	"fmt"
	"os"
)

const N = 200100

func main() {
	var n, x, k int
	var q [N]int

	in := bufio.NewReader(os.Stdin)
	fmt.Fscan(in, &n)

	k = 0
	for i := 0; i < n; i++ {
		fmt.Fscan(in, &x)

		q[k] = x
		k++

		for k > 1 && q[k-2] == q[k-1] {
			q[k-2]++
			k--
		}
	}

	out := bufio.NewWriter(os.Stdout)

	fmt.Fprintln(out, k)
	for i := 0; i < k; i++ {
		fmt.Fprintf(out, "%d ", q[i])
	}
	fmt.Fprint(out, "\n")
	out.Flush()
}
