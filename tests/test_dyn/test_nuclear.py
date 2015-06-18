import os
import sys
import math

# Fisrt, we add the location of the library to test to the PYTHON path
cwd = os.getcwd()
print "Current working directory", cwd
sys.path.insert(1,cwd+"/../../_build/src/mmath")
sys.path.insert(1,cwd+"/../../_build/src/dyn")
sys.path.insert(1,cwd+"/../../_build/src/hamiltonian")


print "\nTest 1: Importing the library and its content"
from cygmmath import *
from cygdyn import *
from cyghamiltonian import *


print "\nTest 2: Coupling nuclear dynamics to external forces - Harmonic oscillator"
def pot(q):
    k = 10.0
    return -k*q, 0.5*k*q*q

mol = Nuclear(1)
mol.mass[0] = 2000.0
mol.q[0] = 1.0
mol.p[0] = 0.0

f = open("_nucl.txt","w")

print "address mol = ", mol

dt = 1.0
for i in xrange(500):
    mol.propagate_p(0.5*dt)
    mol.propagate_q(dt)
    mol.f[0], epot = pot(mol.q[0])
    mol.propagate_p(0.5*dt)

    ekin = compute_kinetic_energy(mol)

    f.write("i= %3i q[0]= %8.5f p[0]= %8.5f  ekin= %8.5f  epot= %8.5f  etot= %8.5f\n" % (i, mol.q[0], mol.p[0], ekin, epot, ekin+epot))

      
f.close()


print "\nTest 3: Coupling nuclear dynamics to external forces - Morse potential"
def pot2(q):
    k = 10.0
    beta = 1.1
    x = math.exp(-beta*q)
    return -k*(x-1.0)*(-beta*x), 0.5*k*(x*x - 2.0*x)

mol = Nuclear(1)
mol.mass[0] = 2000.0
mol.q[0] = 1.0
mol.p[0] = 0.0

f = open("_nucl2.txt","w")

print "address mol = ", mol

dt = 1.0
for i in xrange(2500):
    mol.propagate_p(0.5*dt)
    mol.propagate_q(dt)
    mol.f[0], epot = pot2(mol.q[0])
    mol.propagate_p(0.5*dt)

    ekin = compute_kinetic_energy(mol)

    f.write("i= %3i q[0]= %8.5f p[0]= %8.5f  ekin= %8.5f  epot= %8.5f  etot= %8.5f\n" % (i, mol.q[0], mol.p[0], ekin, epot, ekin+epot))

      
f.close()



