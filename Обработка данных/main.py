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
    
    data1 = np.array(loadData('SCDf.txt'))
    x1 = data1[0,:]
    y1 = data1[1,:]
    data2 = np.array(loadData('Ufull.txt'))
    x2 = data2[:,0]
    y2 = data2[:,1]

    fig = plt.figure()

    print
    type(fig)
    # Создание экземпляра Axes c помощью Figure-метода add_subplot()
    ax = fig.add_subplot(111)
    # или так
    # box = [0.25, 0.5, 0.25, 0.25]
    # Создание экземпляра Axes c помощью Figure-метода add_axes()
    # ax2 = fig.add_axes(box)

    ax.semilogx(x1, y1)
    ax.semilogx(x2, y2)

    # for ax in fig.axes:
    #   ax.grid(True)

    fig.savefig('plot.pdf')


    plt.show()

if __name__ == "__main__":
    main()
