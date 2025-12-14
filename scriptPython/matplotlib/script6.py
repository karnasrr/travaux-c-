# -----------------------------------------------------------------------------
# extrait de https://github.com/rougier/matplotlib-tutorial/blob/master/scripts/exercice_5.py
# Copyright (c) 2015, Nicolas P. Rougier. All Rights Reserved.
# Distributed under the (new) BSD License. See LICENSE.txt for more info.
# Ajout de la fonction spin pour décaler les axes au centre
#Les épines sont les lignes reliant les marques de graduation de l('axe et notant les limites de la zone de données. '
#'Ils peuvent être placés à des positions arbitraires et jusqu')à présent, ils étaient à la limite de l('axe. '
#Nous allons changer cela puisque nous voulons les avoir au milieu. Puisqu')il y en a quatre (en haut/en bas/gauche/droite), nous allons jeter le haut et la droite en réglant leur couleur sur none et nous déplacerons ceux du bas et de la gauche pour coordonner 0 dans les coordonnées de l'espace de données.
# -----------------------------------------------------------------------------
# -----------------------------------------------------------------------------
# Copyright (c) 2015, Nicolas P. Rougier. All Rights Reserved.
# Distributed under the (new) BSD License. See LICENSE.txt for more info.
# -----------------------------------------------------------------------------
import numpy as np
import matplotlib.pyplot as plt

plt.figure(figsize=(8,5), dpi=80)
ax = plt.subplot(111)

ax.spines['right'].set_color('none')
ax.spines['top'].set_color('none')
ax.xaxis.set_ticks_position('bottom')
ax.spines['bottom'].set_position(('data',0))
ax.yaxis.set_ticks_position('left')
ax.spines['left'].set_position(('data',0))

X = np.linspace(-np.pi, np.pi, 256,endpoint=True)
C,S = np.cos(X), np.sin(X)

plt.plot(X, C, color="blue", linewidth=2.5, linestyle="-")
plt.plot(X, S, color="red", linewidth=2.5, linestyle="-")


plt.xlim(X.min()*1.1, X.max()*1.1)
plt.xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi],
       [r'$-\pi$', r'$-\pi/2$', r'$0$', r'$+\pi/2$', r'$+\pi$'])

plt.ylim(C.min()*1.1,C.max()*1.1)
plt.yticks([-1, 0, +1],
       [r'$-1$', r'$0$', r'$+1$'])

plt.show()