def multiplyMatrices(a, b):
    n = len(a)
    count = 0
    result = []
    for r in range(n):
        row = []
        for c in range(n):
            row.append(0)
        result.append(row)

    for r in range(n):
        for c in range(n):
            value = 0.0
            for i in range(n):
                count += 1
                value += a[r][i] * b[i][c]   # count only this line
            result[r][c] = value

    print(count)
    return result


a = [[1,2,3,4,5,6,7],[2,3,4,5,6,7,8],[3,4,5,6,7,8,9],[4,5,6,7,8,9,10],[5,6,7,8,9,10,11]]
b = [[0,9,8,7,6,5,4],[9,8,7,6,5,4,3],[8,7,6,5,4,3,2],[7,6,5,4,3,2,1],[6,5,4,3,2,1,0]]
print(multiplyMatrices(a,b))

#formula is = 125