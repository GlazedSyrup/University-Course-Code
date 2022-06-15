def hollowbox(s,h,w):
    for i in range(h):
        if i == 0 or i == h-1:
            print(s*w)
        else:
            midline = ''
            for j in range(w):
                if j == 0 or j == w-1:
                    midline += s
                else:
                    midline += ' '
            print(midline)

s = input('Symbol = ')
h = int(input('height = '))
w = int(input('width = '))

hollowbox(s, h, w)