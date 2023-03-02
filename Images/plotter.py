import matplotlib.pyplot as plt 

total_points = 4659 - 1619
path_length = 287

f = open("points.txt", "r")

for i in range(total_points):
    line = f.readline()
    x, y = line.split(" ") 
    plt.plot(float(x), float(y), 'bo', markersize=2)
    if (i % 1000 == 0):
        print(i)

f.close()

f = open("path.txt", "r")
for i in range(path_length):
    line = f.readline()
    x, y = line.split(" ") 
    plt.plot(float(x), float(y), 'ro', markersize=2)


f.close()


plt.show()
    
