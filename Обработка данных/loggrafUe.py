import math
import scipy.integrate
import numpy as np
import matplotlib.pyplot as plt




def loadData(name):
    data = []
    with open(name) as f:
        for line in f:
            data.append([float(x) for x in line.split()])
    return data

def main():
    
    data1 = np.array(loadData('Ue.txt'))
    x1 = data1[:,0]
    y1 = data1[:,1]
    # data2 = np.array(loadData('He.txt'))
    y2 = data1[:,2]
    y3 = data1[:,3]
    

    fig = plt.figure()

    print
    type(fig)
    # Создание экземпляра Axes c помощью Figure-метода add_subplot()
    ax = fig.add_subplot(111)
    # или так
    # box = [0.25, 0.5, 0.25, 0.25]
    # Создание экземпляра Axes c помощью Figure-метода add_axes()
    # ax2 = fig.add_axes(box)

    ax.loglog(x1, -y1, color="red")
    ax.loglog(x1, -y2, color="green")
    ax.loglog(x1, -y3, color="blue")
    

    # for ax in fig.axes:
    #   ax.grid(True)

    fig.savefig('plot.pdf')


    plt.show()

if __name__ == "__main__":
    main()
