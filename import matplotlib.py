import matplotlib.pyplot as plt
import numpy


def quick_rand () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quickSort_rand.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработки количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def quick_order () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quickSort_order.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def quick_reverse () -> None:
    x1, y1, z1 = numpy.loadtxt(f"quickSort_revers.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()


def creat_quick_graph() -> None:
    quick_rand()
    quick_order()
    quick_reverse()

    
def insertion_rand () -> None:
    x1, y1, z1 = numpy.loadtxt(f"insertionSort_rand.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def insertion_order () -> None:
    x1, y1, z1 = numpy.loadtxt(f"insertionSort_order.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()

def insertion_reverse () -> None:
    x1, y1, z1 = numpy.loadtxt(f"insertionSort_revers.txt", unpack=True)    
    plt.plot(x1, y1, marker=".")
    plt.plot(x1, z1, marker='.')
    plt.title('Зависимость количества обработке от типа и количества слов')    
    plt.xlabel('Количество слов')
    plt.ylabel('Количество операций')
    plt.show()


def creat_insertion_graph() -> None:
    insertion_rand()
    insertion_order()
    insertion_reverse()
   

creat_quick_graph()
creat_insertion_graph()