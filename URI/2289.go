// URI - Distância de Hamming - 2289
package main

import (
	"bufio"
	"fmt"
	"os"
)

const m1 = 0x5555555555555555  //binary: 0101...
const m2 = 0x3333333333333333  //binary: 00110011..
const m4 = 0x0f0f0f0f0f0f0f0f  //binary:  4 zeros,  4 ones ...
const m8 = 0x00ff00ff00ff00ff  //binary:  8 zeros,  8 ones ...
const m16 = 0x0000ffff0000ffff //binary: 16 zeros, 16 ones ...
const m32 = 0x00000000ffffffff //binary: 32 zeros, 32 ones
const h01 = 0x0101010101010101 //the sum of 256 to the power of 0,1,2,3...

func popcount(x uint64) int {
	x -= (x >> 1) & m1             //put count of each 2 bits into those 2 bits
	x = (x & m2) + ((x >> 2) & m2) //put count of each 4 bits into those 4 bits
	x = (x + (x >> 4)) & m4        //put count of each 8 bits into those 8 bits
	r := int((x * h01) >> 56)      //returns left 8 bits of x + (x<<8) + (x<<16) + (x<<24) + ...
	return r
}

func main() {
	var a, b uint64
	writer := bufio.NewWriter(os.Stdout)
	for {
		fmt.Scan(&a)
		fmt.Scan(&b)
		if a == 0 && b == 0 {
			break
		}

		ans := popcount(a ^ b)

		writer.Write([]byte(fmt.Sprintf("%d\n", ans)))
	}

	writer.Flush()
}
