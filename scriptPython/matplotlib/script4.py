# -----------------------------------------------------------------------------
# extrait de https://github.com/rougier/matplotlib-tutorial/blob/master/scripts/exercice_5.py
# Copyright (c) 2015, Nicolas P. Rougier. All Rights Reserved.
# Distributed under the (new) BSD License. See LICENSE.txt for more info.
# Ajout de xticks / yticks et changement de couleur
# -----------------------------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt

plt.figure(figsize=(8,5), dpi=80)
plt.subplot(111)

X = np.linspace(-np.pi, np.pi, 256,endpoint=True)
C,S = np.cos(X), np.sin(X)

plt.plot(X, C, color="blue", linewidth=2.5, linestyle="-")
plt.plot(X, S, color="green", linewidth=2.5, linestyle="-")

plt.xlim(X.min()*1.1, X.max()*1.1)
plt.xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi])

plt.ylim(C.min()*1.1,C.max()*1.1)
plt.yticks([-1, 0, +1])

plt.show()