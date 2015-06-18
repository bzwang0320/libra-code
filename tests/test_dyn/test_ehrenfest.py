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


print "\nTest 2: Now we will be using model Hamiltonian"
# First, create the Hamiltonian
ham = Hamiltonian_Model(1)  # DAC
ham.set_rep(1)  # adiabatic


# Electronic - 2 levels, starting at 0-th state
el = Electronic(2,0)

# Nuclear DOFs
mol = Nuclear(1)
mol.mass[0] = 2000.0
mol.q[0] = -10.0
mol.p[0] = 20.0


f = open("_ehrenfest.txt","w")
dt = 1.0

# Initialization
ham.set_v([ mol.p[0]/mol.mass[0] ])
epot = compute_potential_energy(mol, el, ham, 0)  # 0 - MF forces
compute_forces(mol, el, ham, 0)


for i in xrange(5000):

    # el-dyn
    el.propagate_electronic(0.5*dt, ham)

    # Nuclear dynamics
    mol.propagate_p(0.5*dt)
    mol.propagate_q(dt)

    ham.set_v([ mol.p[0]/mol.mass[0] ])
    epot = compute_potential_energy(mol, el, ham, 0)  # 0 - MF forces
    compute_forces(mol, el, ham, 0)

    mol.propagate_p(0.5*dt)

    # el-dyn
    el.propagate_electronic(0.5*dt, ham)

    ekin = compute_kinetic_energy(mol)

    f.write("i= %3i q[0]= %8.5f p[0]= %8.5f  ekin= %8.5f  epot= %8.5f  etot= %8.5f  |c0|^2= %8.5f  |c1|^2= %8.5f  Re|c01|= %8.5f\n" % (i, mol.q[0], mol.p[0], ekin, epot, ekin+epot, el.rho(0,0).real, el.rho(1,1).real, el.rho(0,1).real))

      
f.close()

