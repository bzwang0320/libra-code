#*********************************************************************************                     
#* Copyright (C) 2019 Alexey V. Akimov                                                   
#*                                                                                                     
#* This file is distributed under the terms of the GNU General Public License                          
#* as published by the Free Software Foundation, either version 2 of                                   
#* the License, or (at your option) any later version.                                                 
#* See the file LICENSE in the root directory of this distribution   
#* or <http://www.gnu.org/licenses/>.          
#***********************************************************************************
"""
.. module:: ft
   :platform: Unix, Windows
   :synopsis: 
       This module implements the functionality to compute Fourier Transforms

.. moduleauthor:: Alexey V. Akimov

"""

import os
import sys
import math
import copy

#if sys.platform=="cygwin":
#    from cyglibra_core import *
#elif sys.platform=="linux" or sys.platform=="linux2":
#    from liblibra_core import *



def ft(X, wspan, dw, dt):  
    """Discrete Fourier transform

    We do have a number of FT and FFT functions in the Libra core, but
    this one may be also convenient to have

    Args:
        X ( list of floats ): data time-series
        wspan ( float ): is the range (the maximal value) of frequencies we want to compute
        dw ( float ): is the distance between the nearby points on the frequency scale
        dt ( float ): is the time step

    Returns: 
        tuple: (W, J): where

            W ( list of npoints doubles): frequencies               
            J ( list of npoints doubles): amplitudes of the cos-transform

    """

    ############### based on the code from Pyxaid ###################
    sz=len(X)    # the # of input points
    npoints = int(wspan/dw)   # the # of output points    

    J = [0.0] * npoints   # FT
    W = [0.0] * npoints   # frequencies

    for iw in xrange(npoints):
        w = iw * dw

        J[iw] = 1.0  # corresponds to it = 0
        for it in range(1,sz):
            t = it * dt
            J[iw] += 2.0*math.cos(w * t)*X[it]

        W[iw] = w
        J[iw] *= dt

    return W, J


def py_cft(X, dt):  
    """Complex Discrete Fourier transform

    We do have a number of FT and FFT functions in the Libra core, but
    this one may be also convenient to have

    According to this definition: http://mathworld.wolfram.com/DiscreteFourierTransform.html

    Args:
        X ( list of floats ): data time-series
        wspan ( float ): is the range (the maximal value) of frequencies we want to compute
        dw ( float ): is the distance between the nearby points on the frequency scale
        dt ( float ): is the time step

    Returns: 
        tuple: (W, C, S): where

            W ( list of npoints doubles): frequencies               
            C ( list of npoints doubles): amplitudes of the cos-transform
            S ( list of npoints doubles): amplitudes of the sin-transform

    """

    ############### based on the code from Pyxaid ###################
    N = len(X)    # the # of input points
    dv = 1.0/(N*dt)
    dw = 2.0*math.pi*dv

    W = [0.0] * N   # frequencies
    C = [0.0] * N   # FT
    S = [0.0] * N   # FT

    for iw in xrange(N):
        w = iw * dw

        C[iw], S[iw] = 0.0, 0.0
        for it in xrange(N):
            t = it * dt            
            C[iw] += math.cos(w * t)*X[it]   
            S[iw] -= math.sin(w * t)*X[it]

        W[iw] = w

    return W, C, S
