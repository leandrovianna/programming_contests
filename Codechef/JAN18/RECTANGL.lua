local n = io.read('*n')

while n > 0 do
	local v = {}
	for i = 1, 4 do
		v[#v + 1] = io.read('*n')
	end

	table.sort(v)

	if v[1] == v[2] and v[3] == v[4] then
		print("YES")
	else
		print("NO")
	end

	n = n - 1
end
