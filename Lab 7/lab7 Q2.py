## Lab 7 - Q2

energies = [[24,      22,      30,      15,      18,      19],
            [12,      23,      15,      23,      10,     15],
            [11,      13,      22,      13,      21,      14],
            [13,      15,      17,      28,      19,      21],
            [17,      17,      7,       27,      20,      19],
            [17,      17,      7,       27,      20,      19],
            [17,      17,      7,       27,      20,      19],
            [17,      17,      7,       7,      0,      9],
            [17,      7,      7,       27,      20,      19]]

energies2 = [[14,22,14],
            [14,22,14],
            [14,22,14],
            [14,22,14]]



def find_min_seam_cost(energies):
    min_cost = energies

    position = -1

    for x in range(1, len(energies)): # 0-4
        for y in range(len(energies[0])):
            for z in range(-1,2):

                if (z + y) >= len(energies[0]) or (z + y) < 0:
                    position = 0
                    continue

                if z == position:
                    check_min = min_cost[x-1][y+z] + energies[x][y]

                check_eng = min_cost[x-1][y+z] + energies[x][y]
                if check_eng < check_min:
                    check_min = check_eng

            min_cost[x][y] = check_min
            position = -1

    return min_cost
    #min(min_cost[len(energies)-1])


print(find_min_seam_cost(energies))