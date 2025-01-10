# function for line generation
def draw_line(x0, y0, x1, y1):
	length = x1 - x0
	sign = 1
	aid = (y1 - y0) / length
	if length < 0:
		sign = -1
	length = abs(length)
	for i in range(length+1):
		print(x0 + i * sign, round(y0 + i * aid))




draw_line(2, 2, 13, 5)
