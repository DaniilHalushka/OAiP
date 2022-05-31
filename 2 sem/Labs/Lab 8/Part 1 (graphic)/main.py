# библиотеки для построения
import numpy as np
import matplotlib.pyplot as plt
# функция
y = lambda x: (x**3)-50*np.cos(x)
# задание сетки координат
setka = plt.subplots()
# задание области
x = np.linspace(-5, 5, 1000)
# построение графика функции
plt.plot(x, y(x))
# показываем итог
plt.show()