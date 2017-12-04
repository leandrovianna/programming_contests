package main

import "fmt"

func main() {
	var d1, h1, m1, s1,
		d2, h2, m2, s2 int

	fmt.Scanf("Dia %d", &d1)
	fmt.Scanf("%d : %d : %d", &h1, &m1, &s1)
	fmt.Scanf("Dia %d", &d2)
	fmt.Scanf("%d : %d : %d", &h2, &m2, &s2)

	d := d2 - d1
	if d < 0 {
		d += 30
	}

	h := h2 - h1
	if h < 0 {
		h += 24
		d--
	}

	m := m2 - m1
	if m < 0 {
		m += 60
		h--
	}

	s := s2 - s1
	if s < 0 {
		s += 60
		m--
	}

	fmt.Printf("%d dia(s)\n", d)
	fmt.Printf("%d hora(s)\n", h)
	fmt.Printf("%d minuto(s)\n", m)
	fmt.Printf("%d segundo(s)\n", s)
}
