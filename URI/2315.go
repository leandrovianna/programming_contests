// URI - Diferença Fácil Entre Datas - 2315
package main

import "fmt"

var DAYS = []int{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}

type Date struct {
	day, month int
}

func next(d Date) Date {
	if d.day == DAYS[d.month-1] {
		d.day = 1
		if d.month == 12 {
			d.month = 1
		} else {
			d.month++
		}
	} else {
		d.day++
	}

	return d
}

func equal(d1, d2 Date) bool {
	return d1.day == d2.day && d1.month == d2.month
}

func main() {
	var d1, m1, d2, m2 int

	fmt.Scan(&d1, &m1, &d2, &m2)

	date1 := Date{d1, m1}
	date2 := Date{d2, m2}

	answer := 0
	for !equal(date1, date2) {
		answer++
		date1 = next(date1)
	}

	fmt.Println(answer)
}
